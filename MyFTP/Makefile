##
## EPITECH PROJECT, 2021
## Makefile
## File description:
##
##

SRC_S     =		server.c \
				main.c \
				handle_cmd.c \
				commands.c \
				commands1.c \
				commands2.c

OBJ_S     =       $(SRC_S:.c=.o)

SRC_C     =       client.c

OBJ_C     =       $(SRC_C:.c=.o)

NAME_S    =       myftp

NAME_C	=	client

CC      =       gcc

MAKE    =       make

FCLEAN  =       fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage

CFLAGS  =	-Wall -Wextra

all: create_server create_client clean

create_server: $(OBJ_S)
	$(CC) -o $(NAME_S) $(OBJ_S) $(CFLAGS)

create_client: $(OBJ_C)
	$(CC) -o $(NAME_C) $(OBJ_C) $(CFLAGS)

clean:
		rm -f $(OBJ_S)
		rm -f $(OBJ_C)

fclean: clean
		rm -f $(NAME_S)
		rm -f $(NAME_C)

re: fclean all

.PHONY: re fclean clean all