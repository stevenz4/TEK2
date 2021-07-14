##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles with libmy
##

SRC	=	B-CPP-300_rush1/ex03.c \
		B-CPP-300_rush1/player.c \
		point.c \
		vertex.c \
		new.c

OBJ	=	$(SRC:.c=.o)

NAME	=	a.out

LIB	=	lib/my

CC	=	gcc

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

CFLAGS	=	-IB-CPP-300_rush1 -std=gnu11 -Wall -Wextra -g

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
