/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "ncurses.hpp"
#include "sfml.hpp"

int main(int ac, char **av)
{
    (void) av;
    if (ac != 2 || !strcmp(av[1], "-h")) {
        std::cout << "./MyGKrellm [-g][-n][-h]" <<
        std::endl << "-g :\tdisplay in graphical mode" <<
        std::endl << "-n :\tdisplay in text mode" <<
        std::endl << "-h :\tdisplay help" <<
        std::endl;
        return (0);
    }

    if (!strcmp(av[1], "-n")){
        Core core(NCURSES);
        DisplayNcurses(core);
    }
    else if (!strcmp(av[1], "-g")) {
        Core core(SFML);
        DisplaySFML(core);
    }
    return (0);
}