/*
** EPITECH PROJECT, 2021
** main
** File description:
** My FTP
*/

#include "ftp.h"

int write_client(int fd, char *msg)
{
    return write(fd, msg, strlen(msg));
}

int set_ftp_struct(my_ftp *ftp)
{
    ftp->max_client = 30;
    ftp->new_sock_index = 0;
    ftp->addrlen = sizeof(ftp->addr);
    ftp->buffer = malloc(sizeof(char) * 1024);
    for (int j = 0; j < ftp->max_client; j++)
        ftp->client_socket[j] = 0;
    ftp->quit = FALSE;
    ftp->username = strdup("NoUsername");
    ftp->password = strdup("NoPassword");
    ftp->logged = 0;
    if (chdir(ftp->path) != 0)
        return 84;
    return 0;
}

int error_handler(int ac, char **av)
{
    if (ac != 3) {
        printf("Not enough argument\n");
        return 84;
    }
    for (int j = 0; av[1][j] != '\0'; j++)
        if (av[1][j] < 48 || av[1][j] > 57)
            return 84;
    return 0;
}

int destroy_all(my_ftp *ftp)
{
    free(ftp->buffer);
    free(ftp->username);
    free(ftp->password);
    free(ftp->pathname);
    free(ftp->path);
    free(ftp);
    return 0;
}

int main(int ac, char **av)
{
    int port = 0;
    my_ftp ftp;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport\tis the port number on which the ");
        printf("server socket listens\n");
        printf("\tpath\tis the path to the home directory ");
        printf("for the Anonymous user\n");
        return 0;
    } if (error_handler(ac, av) == 84)
        return 84;
    port = atoi(av[1]);
    ftp.path = strdup(av[2]);
    if (set_ftp_struct(&ftp) == 84)
        return 84;
    if (create_server(port, &ftp) == 84)
        return 84;
    return 0;
}

//sfprintf, stdbool