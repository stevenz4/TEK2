/*
** EPITECH PROJECT, 2021
** main
** File description:
** My FTP
*/

#include "ftp.h"

int main(void)
{
    int sock, new_sock;
    SOCKADDR_IN addr;
    char *buffer_r;
    char *buffer_w;
    size_t buffw_size = 1024;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("sock error");
        return 84;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4250);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((new_sock = connect(sock, (SOCKADDR *)&addr, sizeof(addr))) < 0) {
        printf("Connection Failed \n");
        return 84;
    }
    buffer_r = malloc(sizeof(char) * 1024);
    buffer_w = malloc(sizeof(char) * 1024);
    if (read(sock, buffer_r, 1024) != 0)
        printf("%s",buffer_r);
    while(1) {
        getline(&buffer_w, &buffw_size, stdin);
        write(sock, buffer_w, strlen(buffer_w));
        if (read(sock, buffer_r, 1024) != 0)
            printf("%s",buffer_r);
        buffer_r = malloc(sizeof(char) * 1024);
        buffer_w = malloc(sizeof(char) * 1024);
    }
    free(buffer_r);
    free(buffer_w);
    return 0;
}