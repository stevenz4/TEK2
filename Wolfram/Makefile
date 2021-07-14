##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compiles with libmy
##

NAME	=	wolfram

BINARY_PATH := $(shell stack path --local-install-root)

all : build_project

build_project:
	stack build
	cp $(BINARY_PATH)/bin/wolfram-exe ./$(NAME)

clean:
	stack purge

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all