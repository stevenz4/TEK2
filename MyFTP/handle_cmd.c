/*
** EPITECH PROJECT, 2021
** handle_op
** File description:
** My FTP
*/

#include "ftp.h"

char *parse_arg_enter(char *str)
{
    int index = 0;
    char *str_bis = malloc(sizeof(char) * strlen(str));

    for (; str[index] != '\n'; index++)
        str_bis[index] = str[index];
    str_bis[index] = '\0';
    return str_bis;
}

int parse_command(my_ftp *ftp)
{
    char *buffer_cpy = strdup(ftp->buffer);
    char *str;

    ftp->cmd_nb = 0;
    while ((str = strsep(&buffer_cpy, " ")) != NULL) {
        if (strcmp(str, "\n\0") != 0)
            ftp->cmd_nb++;
    }
    ftp->cmd = malloc(sizeof(char *) * ftp->cmd_nb);
    if (ftp->cmd == NULL)
        return 84;
    for (int j = 0; (str = strsep(&ftp->buffer, " ")) != NULL; j++) {
        if (strcmp(str, "\n\0") != 0) {
            ftp->cmd[j] = malloc(sizeof(char) * strlen(str) + 1);
            if (ftp->cmd[j] == NULL)
                return 84;
            ftp->cmd[j] = strdup(parse_arg_enter(str));
        }
    }
    free(buffer_cpy);
    free(str);
    return 0;
}

int handle_cmd(my_ftp *ftp)
{
    printf("[%s] %d", ftp->cmd[0], ftp->cmd_nb);
    if (ftp->cmd_nb == 1) {
        if (strcmp(ftp->cmd[0], "QUIT") == 0)
            check_quit(ftp);
        if (strcmp(ftp->cmd[0], "NOOP") == 0)
            check_noop(ftp);
        if (strcmp(ftp->cmd[0], "HELP") == 0)
            check_help(ftp);
        if (strcmp(ftp->cmd[0], "PWD") == 0)
            check_pwd(ftp);
        if (strcmp(ftp->cmd[0], "PASV") == 0)
            check_pasv(ftp);
        if (strcmp(ftp->cmd[0], "PASS") == 0)
            check_password(ftp);
    }
    return 0;
}

int handle_cmd2(my_ftp *ftp)
{
    if (ftp->cmd_nb > 1) {
        if (strcmp(ftp->cmd[0], "USER") == 0)
            check_username(ftp);
        if (strcmp(ftp->cmd[0], "PASS") == 0)
            check_password(ftp);
        if (strcmp(ftp->cmd[0], "HELP") == 0)
            check_help(ftp);
        if (strcmp(ftp->cmd[0], "CWD") == 0)
            check_cwd(ftp);
        if (strcmp(ftp->cmd[0], "DELE") == 0)
            check_dele(ftp);
    }
    return 0;
}

int check_invalid_cmd(my_ftp *ftp)
{
    if (strcmp(ftp->cmd[0], "QUIT") != 0 && strcmp(ftp->cmd[0], "USER") != 0 &&
    strcmp(ftp->cmd[0], "PASS") != 0 && strcmp(ftp->cmd[0], "PWD") != 0 &&
    strcmp(ftp->cmd[0], "CWD") != 0 && strcmp(ftp->cmd[0], "DELE") != 0 &&
    strcmp(ftp->cmd[0], "HELP") != 0 && strcmp(ftp->cmd[0], "PASV") != 0 &&
    strcmp(ftp->cmd[0], "CDUP") != 0 && strcmp(ftp->cmd[0], "PORT") != 0 &&
    strcmp(ftp->cmd[0], "STOR") != 0 && strcmp(ftp->cmd[0], "RETR") != 0 &&
    strcmp(ftp->cmd[0], "LIST") != 0 && strcmp(ftp->cmd[0], "NOOP") != 0)
        write_client(ftp->new_sock, "500 Unknow command.\r\n");
    return 0;
}