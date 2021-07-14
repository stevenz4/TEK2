##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	src/main.cpp \
		src/error_handler.cpp \
		src/compute_values.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	groundhog

CPP	=	g++

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage

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
