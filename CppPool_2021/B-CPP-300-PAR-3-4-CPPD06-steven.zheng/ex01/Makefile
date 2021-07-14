##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	main.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	my_convert_temp

CPP	=	g++

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME) clean

$(NAME) : $(OBJS)
	$(CPP) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re