##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	Pushswap_Checker.hs

NAME	=	pushswap_checker

all: $(NAME)

$(NAME) : $(SRC)
	ghc -o $(NAME) $(SRC)

clean:
	rm *.hi
	rm *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
