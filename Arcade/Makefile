##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	main.cpp\
		src/LibLoader.cpp\
		src/Arcade.cpp\

SDL2_N =	lib/arcade_sdl2.so

SDL2_F =	src/SDL2/sdl2.cpp

SDL2_O = 	$(SDL2_F:.cpp=.o)

NCURSE_N =	lib/arcade_ncurses.so

NCURSE_F =	src/Ncurse/ncurse.cpp

NCURSE_O = 	$(NCURSE_F:.cpp=.o)

SNAKE_N =	lib/arcade_nibbler.so

SNAKE_F	=	src/snake/snake.cpp

SNAKE_O =	$(SNAKE_F:.cpp=.o)

OBJS	=	$(SRC:.cpp=.o)

NAME	=	arcade

CPP	=	g++

MAKE	=	make

FCLEAN	=	fclean

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

CFLAGS	=	-Wall -Wextra -fPIC

LDFLAGS =  -shared -fno-gnu-unique

all: core graphicals games clean

snake:
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $(SNAKE_N) $(SNAKE_F)

ncurse:
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $(NCURSE_N) $(NCURSE_F) -lncurses

sdl2:
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $(SDL2_N) $(SDL2_F) -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

core: $(OBJS)
	$(CPP) -o $(NAME) $(OBJS) $(CFLAGS) -ldl -g

graphicals: ncurse sdl2

games: snake

clean:
	rm -f $(OBJS)
	rm -f $(SDL2_O)
	rm -f $(NCURSE_O)
	rm -f $(SNAKE_O)

fclean: clean
	rm -f $(NAME)
	rm -f $(SDL2_N)
	rm -f $(NCURSE_N)
	rm -f $(SNAKE_N)

re: fclean all

.PHONY: all core graphicals games snake sdl2 ncurse clean fclean re
