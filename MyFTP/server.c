/*
** EPITECH PROJECT, 2021
** main
** File description:
** My FTP
*/

#include "ftp.h"

int setup_server(int port, my_ftp *ftp)
{
    if ((ftp->sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("sock error");
        return 84;
    } ftp->addr.sin_family = AF_INET;
    ftp->addr.sin_port = htons(port);
    ftp->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(ftp->sock, (SOCKADDR *)&ftp->addr, sizeof(ftp->addr)) < 0) {
        printf("error bind");
        return 84;
    } if (listen(ftp->sock, 3) < 0) {
        printf("listen error");
        return 84;
    }
    write_client(ftp->new_sock, "220 Service ready for new user.\r\n");
    return 0;
}

int setup_sockets(my_ftp *ftp)
{
    FD_ZERO(&ftp->readfds);
    FD_SET(ftp->sock, &ftp->readfds);
    ftp->max_sd = ftp->sock;
    for (int j = 0 ; j < ftp->max_client ; j++) {
        ftp->sfd = ftp->client_socket[j];
        if (ftp->sfd > 0)
            FD_SET(ftp->sfd, &ftp->readfds);
        if (ftp->sfd > ftp->max_sd)
            ftp->max_sd = ftp->sfd;
    }
    printf("max_sd: %d\n", ftp->max_sd);
    if (select(ftp->max_sd + 1, &ftp->readfds, NULL, NULL, NULL) < 0) {
        printf("error activity\n");
        return 84;
    }
    return 0;
}

int incomming_connections(my_ftp *ftp)
{
    if (FD_ISSET(ftp->sock, &ftp->readfds)) {
        if ((ftp->new_sock = accept(ftp->sock,
            (struct sockaddr *)&ftp->addr, (socklen_t *)&ftp->addrlen)) < 0) {
            printf("accept error");
            return 84;
        }
        printf("New connection, socket fd is %d\n", ftp->new_sock);
        write_client(ftp->new_sock, "220 Service ready for new user.\r\n");
        for (int j = 0; j < ftp->max_client; j++) {
            if (ftp->client_socket[j] == 0) {
                ftp->new_sock_index = j;
                ftp->client_socket[j] = ftp->new_sock;
                break;
            }
        }
    }
    return 0;
}

int other_socket(my_ftp *ftp)
{
    for (int j = 0; j < ftp->max_client; j++) {
        ftp->sfd = ftp->client_socket[j];
        if (FD_ISSET(ftp->sfd, &ftp->readfds)) {
            if (read(ftp->client_socket[j], ftp->buffer, 1024) != 0) {
                parse_command(ftp);
                handle_cmd(ftp);
                handle_cmd2(ftp);
                check_invalid_cmd(ftp);
                ftp->buffer = realloc(ftp->buffer, sizeof(char) * 1024);
            } else {
                close(ftp->sfd);
                ftp->client_socket[j] = 0;
            }
        }
    }
    return 0;
}

int create_server(int port, my_ftp *ftp)
{
    if (setup_server(port, ftp) == 84)
        return 84;
    while (ftp->quit == FALSE) {
        if (setup_sockets(ftp) == 84)
            return 84;
        incomming_connections(ftp);
        other_socket(ftp);
    }
    destroy_all(ftp);
    return 0;
}