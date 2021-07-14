##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles with libmy
##

SRC	=	main.c \
		ex00_01.c \
		ex02_03_04_05.c \
		ex06_07_08_09.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring

CC	=	gcc

MAKE	=	make

FCLEAN	=	fclean

CFLAGS	=	-I -std=gnu11 -Wall -Wextra -g

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
