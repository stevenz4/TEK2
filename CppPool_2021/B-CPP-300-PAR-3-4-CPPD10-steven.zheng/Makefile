##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	main.cpp \
		Federation.cpp \
		WarpSystem.cpp \
		Borg.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	a.out

CPP	=	g++

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

CFLAGS	=	-I -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME) : $(OBJS)
	$(CPP) -o $(NAME) $(OBJS) -I -Wall -Wextra -Werror

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
