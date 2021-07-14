/*
** EPITECH PROJECT, 2021
** all commands part 3
** File description:
** My FTP
*/

#include "ftp.h"

int check_pasv(my_ftp *ftp)
{
    if (ftp->cmd_nb != 2)
        return 84;
    write_client(ftp->new_sock, "227 Passive mode activated\r\n");
    return 0;
}

char *add_crlf(char *src)
{
    char *str = malloc(sizeof(char) * strlen(src) + 3);
    int index = 0;

    for (; src[index] != '\0'; index++)
        str[index] = src[index];
    str[index] = '\r';
    str[index + 1] = '\n';
    str[index + 2] = '\0';
    return str;
}