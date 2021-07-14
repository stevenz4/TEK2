/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Player
*/

#include "Player.hpp"

void Player::input(const std::vector<GameObject*> &_mapObject)
{
    switch (_P){
    case 1:
        if (IsKeyDown(KEY_W) && checkCollision(UP, _mapObject) == false)
            this->move(UP, _moveSpeed);
        if (IsKeyDown(KEY_S) && checkCollision(DOWN, _mapObject) == false)
            this->move(DOWN, _moveSpeed);
        if (IsKeyDown(KEY_A) && checkCollision(LEFT, _mapObject) == false)
            this->move(LEFT, _moveSpeed);
        if (IsKeyDown(KEY_D) && checkCollision(RIGHT, _mapObject) == false)
            this->move(RIGHT, _moveSpeed);
        if (IsKeyPressed(KEY_F))
            this->plantBomb();
        break;
    case 2:
        if (IsKeyDown(KEY_UP) && checkCollision(UP, _mapObject) == false)
            this->move(UP, _moveSpeed);
        if (IsKeyDown(KEY_DOWN) && checkCollision(DOWN, _mapObject) == false)
            this->move(DOWN, _moveSpeed);
        if (IsKeyDown(KEY_LEFT) && checkCollision(LEFT, _mapObject) == false)
            this->move(LEFT, _moveSpeed);
        if (IsKeyDown(KEY_RIGHT) && checkCollision(RIGHT, _mapObject) == false)
            this->move(RIGHT, _moveSpeed);
        if (IsKeyPressed(KEY_SPACE))
            this->plantBomb();
        break;
    case 3:
        if (IsKeyDown(KEY_KP_8) && checkCollision(UP, _mapObject) == false)
            this->move(UP, _moveSpeed);
        if (IsKeyDown(KEY_KP_5) && checkCollision(DOWN, _mapObject) == false)
            this->move(DOWN, _moveSpeed);
        if (IsKeyDown(KEY_KP_4) && checkCollision(LEFT, _mapObject) == false)
            this->move(LEFT, _moveSpeed);
        if (IsKeyDown(KEY_KP_6) && checkCollision(RIGHT, _mapObject) == false)
            this->move(RIGHT, _moveSpeed);
        if (IsKeyPressed(KEY_KP_0))
            this->plantBomb();
        break;
    case 4:
        if (IsKeyDown(KEY_I) && checkCollision(UP, _mapObject) == false)
            this->move(UP, _moveSpeed);
        if (IsKeyDown(KEY_K) && checkCollision(DOWN, _mapObject) == false)
            this->move(DOWN, _moveSpeed);
        if (IsKeyDown(KEY_J) && checkCollision(LEFT, _mapObject) == false)
            this->move(LEFT, _moveSpeed);
        if (IsKeyDown(KEY_L) && checkCollision(RIGHT, _mapObject) == false)
            this->move(RIGHT, _moveSpeed);
        if (IsKeyPressed(KEY_M))
            this->plantBomb();
        break;
    }
}

bool Player::checkCollision(Dir dir, const std::vector<GameObject*> &_mapObject)
{
    if (dir == UP) {
        BoundingBox player = {this->getPosition(), this->getPosition()};
        for (GameObject *i : _mapObject) {
            BoundingBox box = {{i->getPosition().x - 1.5f, i->getPosition().y - 1.0f, i->getPosition().z - 1.5f}, {i->getPosition().x + 1.5f, i->getPosition().y + 1.0f, i->getPosition().z + 2.0f}};
            if (CheckCollisionBoxes(player, box))
                return true;
        }
    }
    if (dir == DOWN) {
        BoundingBox player = {this->getPosition(), this->getPosition()};
        for (GameObject *i : _mapObject) {
            BoundingBox box = {{i->getPosition().x - 1.5f, i->getPosition().y - 1.0f, i->getPosition().z - 2.5f}, {i->getPosition().x + 1.5f, i->getPosition().y + 1.0f, i->getPosition().z + 0.5f}};
            if (CheckCollisionBoxes(player, box))
                return true;
        }
    }
    if (dir == LEFT) {
        BoundingBox player = {this->getPosition(), this->getPosition()};
        for (GameObject *i : _mapObject) {
            BoundingBox box = {{i->getPosition().x - 0.5f, i->getPosition().y - 1.0f, i->getPosition().z - 2.0f}, {i->getPosition().x + 2.5f, i->getPosition().y + 1.0f, i->getPosition().z + 1.8f}};
            if (CheckCollisionBoxes(player, box))
                return true;
        }
    }
    if (dir == RIGHT) {
        BoundingBox player = {this->getPosition(), this->getPosition()};
        for (GameObject *i : _mapObject) {
            BoundingBox box = {{i->getPosition().x - 1.8f, i->getPosition().y - 1.0f, i->getPosition().z - 2.0f}, {i->getPosition().x + 1.0f, i->getPosition().y + 1.0f, i->getPosition().z + 1.5f}};
            if (CheckCollisionBoxes(player, box))
                return true;
        }
    }
    return false;
}

void Player::input(bool ia, const std::vector<GameObject*> &_mapObject)
{
    if (checkCollision(dir, _mapObject) == true || (std::clock() - _clock) / CLOCKS_PER_SEC > 3) {
            plantBomb();
            _clock = std::clock();
        }
    if (checkCollision(dir, _mapObject) == false)
        this->move(this->dir, _moveSpeed);
    else if (checkCollision(DOWN, _mapObject) == false && this->bf_dir != DOWN) {
        this->move(DOWN, _moveSpeed);
        this->bf_dir = this->dir;
        this->dir = DOWN;
    }
    else if (checkCollision(UP, _mapObject) == false && this->bf_dir != UP) {
        this->move(UP, _moveSpeed);
        this->bf_dir = this->dir;
        this->dir = UP;
        
    }
    else if (checkCollision(LEFT, _mapObject) == false && this->bf_dir != LEFT) {
        this->move(LEFT, _moveSpeed);
        this->bf_dir = this->dir;
        this->dir = LEFT;
        
    }
    else if (checkCollision(RIGHT, _mapObject) == false && this->bf_dir != RIGHT) {
        this->move(RIGHT, _moveSpeed);
        this->bf_dir = this->dir;
        this->dir = RIGHT;
    }
}

void Player::plantBomb()
{
    if (_bombNb != 0) {
        int x = getPosition().x;
        int z = getPosition().z;
        Vector3 bombPosition;

        if (x % 3 != 0)
            x += 3;
        if (z % 3 != 0)
            z += 3;
        x = x / 3 * 3;
        z = z / 3 * 3;
        bombPosition = {(float)x, getPosition().y, (float)z};
        for (Bomb * i: _bomb) {
            if (i->getBombPosed() == false) {
                i->setPosition(bombPosition);
                i->setBombPosed(true);
                _bombNb -= 1;
                break;
            }
        }
    }
}

void Player::manageBomb(std::vector<GameObject*> &mapObject,  std::vector<Player*> &playerObject, Player &player)
{
    for (Bomb *bomb : _bomb) {
        if (bomb->getBombPosed() == true)
            bomb->manageBomb(mapObject, playerObject, player);
        if (bomb->getBombPosed() == false) {
            if (_bombNb < _bombMax)
                _bombNb += 1;
        }
    }
}