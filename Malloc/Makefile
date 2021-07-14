##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles with libmy
##

SRC	=	main.c

NAME	=	libmy_malloc.so

SRC_L	=	my_malloc.c \
			my_free.c \
			my_calloc.c \
			my_realloc.c \
			my_reallocarray.c

CC	=	gcc

MAKE	=	make

FCLEAN	=	fclean

CFLAGS	=	-Wall -Wextra -g

all: create_lib create_bin

create_lib :
	$(CC) $(CFLAGS) -shared -fPIC -o $(NAME) $(SRC_L)

create_bin : 
	$(CC) $(CFLAGS) -ldl -o a.out $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all
