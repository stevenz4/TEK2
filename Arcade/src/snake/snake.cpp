/*
** EPITECH PROJECT, 2021
** snake
** File description:
** Arcade
*/

#include "snake.hpp"
#include "../LibLoader.hpp"

Snake::Snake(IGraphics *lib_graphics)
{
    this->graphics = lib_graphics;
    setupSnake();
}

Snake::~Snake()
{
}

int Snake::setupSnake()
{
    this->direction = START;
    this->mapX = 0;
    this->mapY = 0;
    this->snake_length = 4;
    this->gameOver = false;
    this->closeGame = false;
    this->score = 0;
    this->readMap();
    this->convertMap();
    this->gameLoop();
    return 0;
}

int Snake::setupGame()
{
    this->graphics->createWin();
    this->graphics->createSound("assets/music.wav");
    return 0;
}


int Snake::readMap()
{
    int x = 0;
    int y = 0;
    std::ifstream my_file("src/snake/map.txt");

    if (my_file.is_open()) {
        this->map << my_file.rdbuf();
        my_file.close();
    } else {
        std::cout << "Unable to open the file" << std::endl;
        return 84;
    }
    for (; this->map.str()[x] != '\n'; x++);
    for (int j = 0; this->map.str()[j] != '\0'; j++)
        if (this->map.str()[j] == '\n')
            y++;
    this->mapX = x;
    this->mapY = y;
    return 0;
}

int Snake::convertMap()
{
    int count = 0;
    int index = 0;

    this->map_c = new int *[this->mapY + 1];
    for (int j = 0; j < this->mapY; j++)
        this->map_c[j] = new int[this->mapX + 1];
    for (int j = 0; j < this->mapY; j++, count++) {
        for (int k = 0; k < this->mapX; k++, count++) {
            if (map.str()[count] == '#')
                this->map_c[j][k] = -1;
            if (map.str()[count] == ' ')
                this->map_c[j][k] = 0;
            if (map.str()[count] == 'O') {
                this->map_c[j][k] = 1;
                this->fruitX = k;
                this->fruitY = j;
            } if (map.str()[count] == 'P') {
                this->map_c[j][k] = 2;
                this->tailX[index] = k;
                this->tailY[index] = j;
                index++;
            } if (map.str()[count] == 'p') {
                this->map_c[j][k] = 3;
                this->tailX[index] = k;
                this->tailY[index] = j;
                index++;
            }
        }
    }
    return 0;
}

int Snake::placeFruit()
{
    fruitX = rand() % ((mapX - 2) - 1 + 1) + 1;
    fruitY = rand() % ((mapY - 2) - 1 + 1) + 1;
    for (int j = 0; j < snake_length; j++) {
        if ((fruitX == tailX[j]) && (fruitY == tailY[j])) {
            placeFruit();
            return 0;
        }
    }
    this->map_c[fruitY][fruitX] = 1;
    return 0;
}

int Snake::drawMap()
{
    int xcrate = this->graphics->WIDTH / 2 - this->mapX * 20 / 2;
    int ycrate = this->graphics->HEIGHT / 2 - this->mapY * 20 / 2;

    for (int j = 0; j < this->mapY; j++, ycrate+=20) {
        for (int k = 0, xcrate = this->graphics->WIDTH / 2 - this->mapX * 20 / 2; k < this->mapX; k++, xcrate += 20) {
            if (map_c[j][k] == -1)
                graphics->drawImage("assets/texture/crate.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 0)
                graphics->drawImage("assets/texture/ground.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 1)
                graphics->drawImage("assets/texture/fraise.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 2 && (direction == START || direction == LEFT))
                graphics->drawImage("assets/texture/shead_L.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 2 && direction == RIGHT)
                graphics->drawImage("assets/texture/shead_R.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 2 && direction == UP)
                graphics->drawImage("assets/texture/shead_U.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 2 && direction == DOWN)
                graphics->drawImage("assets/texture/shead_D.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
            if (map_c[j][k] == 3)
                graphics->drawImage("assets/texture/stail.jpg", {0, 0, 20, 20}, {xcrate, ycrate, 20, 20});
        }
    }
    return 0;
}

int Snake::snakeEvents()
{
    for (int j = 1; j < snake_length; j++) {
        if ((tailX[0] == tailX[j]) && (tailY[0] == tailY[j])) {
            this->gameOver = true;
        }
    }
    if (tailX[0] == 1 || tailX[0] == mapX - 1 || tailY[0] == 1 ||
        tailY[0] == mapY - 1)
        this->gameOver = true;
    if (tailX[0] == this->fruitX && tailY[0] == this->fruitY) {
        score += 10;
        this->placeFruit();
        snake_length++;
    }
    return 0;
}

int Snake::moveSnake(int y, int x)
{
    for (int j = snake_length; j > 0; j--) {
        tailX[j] = tailX[j - 1];
        tailY[j] = tailY[j - 1];
    }
    tailX[0] = x;
    tailY[0] = y;
    map_c[tailY[0]][tailX[0]] = 2;
    for (int j = 1; j < snake_length; j++)
        map_c[tailY[j]][tailX[j]] = 3;
    map_c[tailY[snake_length]][tailX[snake_length]] = 0;
    return 0;
}

int Snake::movePlayer(int dir)
{
    if (dir == 'z' && direction != DOWN)
        direction = UP;
    if (dir == 'q' && direction != RIGHT)
        direction = LEFT;
    if (dir == 's' && direction != UP)
        direction = DOWN;
    if (dir == 'd' && direction != LEFT)
        direction = RIGHT;
    if (dir == 84)
        this->closeGame = true;
    switch (direction) {
        case UP:
            moveSnake(tailY[0] - 1, tailX[0]);
            break;
        case LEFT:
            moveSnake(tailY[0], tailX[0] - 1);
            break;
        case DOWN:
            moveSnake(tailY[0] + 1, tailX[0]);
            break;
        case RIGHT:
            moveSnake(tailY[0], tailX[0] + 1);
            break;
        default:
            break;
    } 
    return 0;
}

int Snake::drawInterface()
{
    std::string score_text = std::to_string(this->score);
    graphics->drawText("Score: ", 20, 200, 50);
    graphics->drawText(score_text.c_str(), 20, 400 , 50);
    return 0;
}

int Snake::resetSnake()
{
    int count = 0;
    int index = 0;

    this->direction = START;
    this->snake_length = 4;
    this->gameOver = false;
    this->closeGame = false;
    this->scoreboard.push_back(this->score);
    this->score = 0;
    memset(this->tailX, 0, sizeof(this->tailX));
    memset(this->tailY, 0, sizeof(this->tailY));
    for (int j = 0; j < this->mapY; j++, count++) {
        for (int k = 0; k < this->mapX; k++, count++) {
            if (map.str()[count] == '#')
                this->map_c[j][k] = -1;
            if (map.str()[count] == ' ')
                this->map_c[j][k] = 0;
            if (map.str()[count] == 'O') {
                this->map_c[j][k] = 1;
                this->fruitX = k;
                this->fruitY = j;
            } if (map.str()[count] == 'P') {
                this->map_c[j][k] = 2;
                this->tailX[index] = k;
                this->tailY[index] = j;
                index++;
            } if (map.str()[count] == 'p') {
                this->map_c[j][k] = 3;
                this->tailX[index] = k;
                this->tailY[index] = j;
                index++;
            }
        }
    }
    return 0;
}

int Snake::loseEvent()
{
    int val = graphics->getInput();
    int index = 0;

    std::string score_text = std::to_string(this->score);
    std::sort(this->scoreboard.begin(), this->scoreboard.end(), std::greater<>()); 
    graphics->drawText("Score: ", 30, 170, 300);
    graphics->drawText(score_text.c_str(), 30, 370, 300);
    graphics->drawText("Scoreboard ", 20, 940, 150);
    for (auto score = this->scoreboard.begin(); score != this->scoreboard.end() && index < 10; score++, index++) {
        graphics->drawText(std::to_string(index + 1), 20, 920, 190 + (index * 30));
        graphics->drawText(std::to_string(this->scoreboard.at(index)), 20, 1000, 190 + (index * 30));
    }
    if (val == 'r') {
        resetSnake();        
        return 0;
    } else if (val == 84)
        this->closeGame = true;
    return 0;
}

int Snake::gameLoop()
{
    while (this->closeGame == false) {
        if (this->gameOver == false) {
            this->graphics->renderClear();
            this->graphics->drawImage("assets/wallpaper.jpg", {0, 0, 1920, 1080}, {0, 0, this->graphics->WIDTH, this->graphics->HEIGHT});
            drawInterface();
            movePlayer(this->graphics->getInput());
            snakeEvents();
            drawMap();
            this->graphics->renderPresent();
        } else {
            this->graphics->renderClear();
            this->graphics->drawImage("assets/wallpaper.jpg", {0, 0, 1920, 1080}, {0, 0, this->graphics->WIDTH, this->graphics->HEIGHT});
            loseEvent();
            this->graphics->renderPresent();
        } usleep(40000);
    }
    return 0;
}

extern "C" Snake *create_obj(IGraphics *lib)
{
    Snake *newone = new Snake(lib);

    return newone;
}