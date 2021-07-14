/*
** EPITECH PROJECT, 2021
** snake
** File description:
** Arcade
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include "../IGraphics.hpp"

typedef IGraphics*(*Load)();

enum Direction {START, LEFT, RIGHT, UP, DOWN};

class Snake {
    public:
        Snake(IGraphics *);
        int setupSnake();
        int setupGame();
        int readMap();
        int convertMap();
        int placeFruit();
        int moveSnake(int y, int x);
        int gameLoop();
        int movePlayer(int dir);
        int snakeEvents();
        int loseEvent();
        int resetSnake();
        int drawMap();
        int drawInterface();
        ~Snake();
    private:
        Direction direction;
        IGraphics *graphics;
        std::vector<int> scoreboard;
        int snake_length;
        std::stringstream map;
        int **map_c;
        int mapX;
        int mapY;
        int tailX[100];
        int tailY[100];
        int snakeX;
        int snakeY;
        int fruitX;
        int fruitY;
        int score;
        bool gameOver;
        bool closeGame;
    protected:
};


#endif /* !SNAKE_HPP_ */
