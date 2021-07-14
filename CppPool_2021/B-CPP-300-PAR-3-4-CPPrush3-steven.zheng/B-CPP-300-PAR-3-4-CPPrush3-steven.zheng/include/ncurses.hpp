/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <cstring>
#include <iostream>
#include "Core.hpp"

void DisplayNcurses(Core core);
void DisplayCPU(Core core);
void DisplayRAM(Core core);
void DisplayNetwork(Core core);
void Display(Core core);

#endif
