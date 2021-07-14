/*
** EPITECH PROJECT, 2021
** IOstream
** File description:
** Exercise 00
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    int no_file = 0;
    char c;
    std::ifstream my_file;

    if (ac == 1)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (int j = 1; j < ac; j++) {
        std::ifstream my_file (av[j]);
        if (my_file) {
            while(my_file.get(c))
                std::cout << c;
            my_file.close();
        } else {
            std::cerr << "my_cat: " << av[j] <<
            ": No such file or directory" << std::endl;
            no_file = 1;
        }
    }
    return no_file;
}