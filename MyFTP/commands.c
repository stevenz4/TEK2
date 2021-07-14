/*
** EPITECH PROJECT, 2021
** all commands part 1
** File description:
** My FTP
*/

#include "ftp.h"

int check_username(my_ftp *ftp)
{
    if (ftp->cmd_nb != 2)
        return 84;
    if (ftp->logged == 1) {
        write_client(ftp->new_sock, "530 Can't change from guest user\r\n");
        return 84;
    }
    ftp->username = strdup(ftp->cmd[1]);
    write_client(ftp->new_sock,
    "331 Please specify the password\r\n");
    return 0;
}

int check_password(my_ftp *ftp)
{
    if (strcmp(ftp->username, "NoUsername") == 0 && ftp->logged == 0) {
        write_client(ftp->new_sock, "332 Need account for login\r\n");
        return 84;
    } if (strcmp(ftp->password, "NoPassword") != 0 && ftp->logged == 1) {
        write_client(ftp->new_sock, "530 Can't insert new password\r\n");
        return 84;
    } if (strcmp(ftp->username, "Anonymous") != 0) {
        write_client(ftp->new_sock, "530 Incorrect username\r\n");
        return 84;
    }
    if (ftp->cmd_nb == 2)
        ftp->password = strdup(ftp->cmd[1]);
    else
        ftp->password = strdup("Empty");
    ftp->logged = 1;
    write_client(ftp->new_sock, "230 Login successful\r\n");
    return 0;
}

int check_quit(my_ftp *ftp)
{
    write_client(ftp->new_sock, "221 Goodbye\r\n");
    ftp->client_socket[ftp->new_sock_index] = 0;
    close(ftp->new_sock);
    return 0;
}

int check_noop(my_ftp *ftp)
{
    if (check_logged(ftp) == 84)
        return 84;
    write_client(ftp->new_sock, "200 Do nothing\r\n");
    return 0;
}