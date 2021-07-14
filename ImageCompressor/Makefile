##
## EPITECH PROJECT, 2020
## Doop
## File description:
## doop
##

NAME            = imageCompressor

BINARY_PATH 	:=	$(shell stack path --local-install-root)

all:	stack_build

stack_build:
	stack build
	cp $(BINARY_PATH)/bin/compressor-exe ./$(NAME)

tests_run:
	./test/tests

clean:
	stack purge

fclean: clean
	rm -f $(NAME)

re:     fclean all

ra: fclean algo

.PHONY: all algo clean fclean re ra $name
