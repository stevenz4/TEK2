/*
** EPITECH PROJECT, 2021
** Include
** File description:
** My FTP
*/

#ifndef FTP_H_
#define FTP_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

typedef enum {TRUE, FALSE} bool;
typedef struct ftp_st {
    int client_socket[30];
    int max_client;
    int sock;
    int new_sock;
    int new_sock_index;
    SOCKADDR_IN addr;
    int addrlen;
    char *buffer;
    fd_set readfds;
    int sfd;
    int max_sd;
    char *username;
    char *password;
    char **cmd;
    int cmd_nb;
    bool quit;
    char *pathname;
    char *path;
    int logged;
} my_ftp;

int setup_server(int port, my_ftp *ftp);
int setup_sockets(my_ftp *ftp);
int incomming_connections(my_ftp *ftp);
int other_socket(my_ftp *ftp);
int create_server(int port, my_ftp *ftp);

int write_client(int fd, char *msg);
int destroy_all(my_ftp *ftp);

char *parse_arg_enter(char *str);
int parse_command(my_ftp *ftp);
int handle_cmd(my_ftp *ftp);
int handle_cmd2(my_ftp *ftp);
int check_invalid_cmd(my_ftp *ftp);

int check_username(my_ftp *ftp);
int check_password(my_ftp *ftp);
int check_password2(my_ftp *ftp);
int check_quit(my_ftp *ftp);
int check_noop(my_ftp *ftp);
int check_help(my_ftp *ftp);
int check_pwd(my_ftp *ftp);
int check_cwd(my_ftp *ftp);
int check_logged(my_ftp *ftp);
int check_dele(my_ftp *ftp);
int check_pasv(my_ftp *ftp);

char *add_crlf(char *src);

#endif /* !FTP_H_ */
