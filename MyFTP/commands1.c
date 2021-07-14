/*
** EPITECH PROJECT, 2021
** all commands part 2
** File description:
** My FTP
*/

#include "ftp.h"

int check_help(my_ftp *ftp)
{
    if (check_logged(ftp) == 84)
        return 84;
    write_client(ftp->new_sock,
    "214 USER PASS QUIT NOOP HELP PWD CWD DELE PASV\r\n");
    return 0;
}

int check_pwd(my_ftp *ftp)
{
    char *dest;

    ftp->pathname = malloc(sizeof(char) * 256);
    if (check_logged(ftp) == 84)
        return 84;
    if (getcwd(ftp->pathname, 256) == NULL)
        printf("getcwd erro\n");
    else {
        dest = malloc(sizeof(char) * strlen(ftp->pathname) + 4);
        strcat(dest, "257 ");
        strcat(dest, ftp->pathname);
        write_client(ftp->new_sock, add_crlf(dest));
    }
    free(ftp->pathname);
    free(dest);
    return 0;
}

int check_cwd(my_ftp *ftp)
{
    char *path = malloc(sizeof(char) * 500);

    if (check_logged(ftp) == 84) {
        free(path);
        return 84;
    } if (path == NULL) {
        printf("check_cwd malloc error\n");
        return 84;
    }
    for (int j = 0; ftp->cmd[1][j] != '\0'; j++)
        path[j] = ftp->cmd[1][j];
    if (ftp->cmd_nb != 2)
        return 84;
    if (chdir(path) != 0) {
        write_client(ftp->new_sock, "550 Failed to change directory\r\n");
        return 84;
    } write_client(ftp->new_sock,
    "250 Requested file action okay, completed\r\n");
    return 0;
}

int check_dele(my_ftp *ftp)
{
    if (check_logged(ftp) == 84)
        return 84;
    if (remove(ftp->cmd[1]) != 0) {
        printf("[%s]\n", ftp->cmd[1]);
        write_client(ftp->new_sock, "550 No File with this name\r\n");
        return 0;
    }
    write_client(ftp->new_sock, "250 File Deleted\r\n");
    return 0;
}

int check_logged(my_ftp *ftp)
{
    if (ftp->logged == 0 || strcmp(ftp->username, "Anonymous") != 0) {
        write_client(ftp->new_sock, "530 Logged in error\r\n");
        return 84;
    }
    return 0;    
}