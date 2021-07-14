##
## EPITECH PROJECT, 2018
## FASTAtools
## File description:
## Compile the program
##





NAME = 		MyGKrellm

CC =		g++

SRC =		src/main.cpp		\
			src/modules/Core.cpp	\
			src/modules/CoresInfo.cpp	\
			src/modules/Hostname_Username.cpp	\
			src/modules/Network.cpp	\
			src/modules/Ram.cpp	\
			src/modules/SysName_KernelVer.cpp	\
			src/modules/Time.cpp	\
			src/ncurses/ncursesMain.cpp	\
			src/sfml/sfmlMain.cpp \
			src/sfml/sfml_class.cpp

TSRC =	tests/test_project.cpp \
		$(SRC)

OBJ =		$(SRC:.cpp=.o)

CPPFLAGS = 	-Wall -Wextra -I./include/

SFLMFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NCURSESFLAGS = -lncurses

TFLAGS = 	--coverage -lcriterion -I./include/

RED	=	\033[31;1m

GRE	=	\033[32;1m

YEL	=	\033[33;1m

ORA	=	\033[33;5m

BLU	=	\033[34;1m

CYAN	=	\033[36;1m

PUR	=	\033[35;1m

END	=	\033[0m

TIR =	\xe2\x94\x81

RM	=	rm -f

all: 		$(NAME)

$(NAME): 	$(OBJ)
		@echo -e "\xe2\x94\x8f$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)\xe2\x94\x93"
		@echo -e "\xe2\x94\x83$(GRE)                Everything compiled without any issues.                $(END)\xe2\x94\x83"
		@$(MAKE1)
		@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(SFLMFLAGS) $(NCURSESFLAGS) $(LDFLAGS)
		@echo -e "\xe2\x94\x97$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(PUR)~~~~~~~~ MyGKrellm READY ~~~~~~~~$(END)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)\xe2\x94\x9b"
		@echo

clean:
		@echo -e "$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)"
		@echo -e "$(YEL)Cleaning the folder !$(END)"
		@$(foreach var, $(OBJ), if [ -e $(var) ] ; then 			\
			printf "{$(RED)\xe2\x9c\x98$(END)} $(CYAN)$(var)$(END)\n" 	\
			&& $(RM) $(var) ; fi ;)
		@$(RM) vgcore.*
		@echo -e "$(GRE)Folder cleaned !$(END)"

fclean:		clean
		@echo -e "$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)"
		@echo -e "$(YEL)Deleting the binary !$(END)"
		@if [ -e $(NAME) ] ; then 						\
			printf "{$(RED)\xe2\x9c\x98$(END)} $(CYAN)$(NAME)$(END)\n" 	\
			&& rm -f $(NAME) ; fi
		@echo -e "$(GRE)Binary gone !$(END)"
		@echo -e "$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)$(TIR)"

re: 		fclean all

%.o:		%.cpp
		@echo -e "{$(GRE)\xe2\x9c\x93$(END)} $(CYAN)$<$(END) $(YEL)\xe2\x9f\xb6$(END) $(CYAN)$@$(END)"
		@$(CC) $(CPPFLAGS) $(SFLMFLAGS) $(NCURSESFLAGS) -o $@ -c $<

tests_run :
	$(CC) -o unit_tests $(TSRC) $(TFLAGS)
	./unit_tests
	rm test_project.gcno
	gcovr
	make remove_test

remove_test :
	rm *.gcno
	rm *.gcda
	rm unit_tests


.PHONY: 	all clean fclean re tests_run remove_test