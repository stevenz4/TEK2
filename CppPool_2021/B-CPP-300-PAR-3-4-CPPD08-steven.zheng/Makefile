##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	main.cpp \
		Droid.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	a.out

CPP	=	g++

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

CPPFLAGS	=	-I -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME) : $(OBJS)
	$(CPP) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
