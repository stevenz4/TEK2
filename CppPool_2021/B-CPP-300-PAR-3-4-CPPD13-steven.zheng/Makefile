##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	ex04/Toy.cpp \
		ex04/Picture.cpp \
		ex04/Woody.cpp \
		ex04/Buzz.cpp

TSRC =	tests/test_project.cpp \
		$(SRC)

CPP	=	g++

TESTS_FLAGS     =       -o unit_tests -lcriterion --coverage -Iinclude/

tests_run :
	$(CPP) -o unit_tests $(TSRC) $(TESTS_FLAGS)
	./unit_tests
	rm test_project.gcno
	gcovr
	make remove_test

remove_test :
	rm *.gcno
	rm *.gcda
	rm unit_tests

.PHONY: tests_run remove_test
