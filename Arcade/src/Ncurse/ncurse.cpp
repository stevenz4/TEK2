/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ncurse
*/

#include <ncurses.h>
#include <stdio.h>
#include "ncurse.hpp"

Ncurse::Ncurse()
{
    win = nullptr;
    this->isOpen = true;
}

Ncurse::~Ncurse()
{
    endwin();
}

int Ncurse::createWin()
{
    win = initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    noecho();
    return 0;
}

int Ncurse::getInput()
{
    timeout(100);
    int val = wgetch(win);
    clear();
    switch (val)
    {
        case 'm':
            endwin();
            return 84;
            break;
        default:
            return (val);
    }
}

void Ncurse::drawImage(const std::string imageName, rect_t src, rect_t dst)
{
    if (!imageName.compare("assets/texture/crate.jpg")) {
        attron(COLOR_PAIR(1));
        mvprintw((LINES / 5 + dst.y / 20), (COLS / 5 + dst.x / 20), "X");
        attroff(COLOR_PAIR(1));
    }
    if (!imageName.compare("assets/texture/ground.jpg")) {
        attron(COLOR_PAIR(3));
        mvprintw((LINES / 5 + dst.y / 20), (COLS / 5 + dst.x / 20), " ");
        attroff(COLOR_PAIR(3));
    } if (!imageName.compare("assets/texture/fraise.jpg")){
        attron(COLOR_PAIR(4));
        mvprintw((LINES / 5 + dst.y / 20), (COLS / 5 + dst.x / 20), "*");
        attroff(COLOR_PAIR(4));
    }
    if (!imageName.compare("assets/texture/shead_L.jpg") || !imageName.compare("assets/texture/shead_R.jpg") || !imageName.compare("assets/texture/shead_U.jpg") || !imageName.compare("assets/texture/shead_D.jpg")) {
        attron(COLOR_PAIR(2));
        mvprintw((LINES / 5 + dst.y / 20), (COLS / 5 + dst.x / 20), "O");
        attroff(COLOR_PAIR(2));
    }
    if (!imageName.compare("assets/texture/stail.jpg")){
        attron(COLOR_PAIR(2));
        mvprintw((LINES / 5 + dst.y / 20), (COLS / 5 + dst.x / 20), "o");
        attroff(COLOR_PAIR(2));
    }
    if (!imageName.compare("assets/texture/snake_image.png")) {
        drawText("Press P to play Nibbler", 0, 350, 120);
        drawText("Press R to restart the game", 0, 350, 140);
        drawText("Press M to quit", 0, 350, 160);
    }
}

void Ncurse::drawText(const std::string text, int ftsize, int x, int y)
{
    mvprintw(y / (HEIGHT/LINES), x / (WIDTH/COLS), text.c_str());
}

extern "C" Ncurse *create_obj()
{
    Ncurse *newone = new Ncurse;

    return newone;
}
