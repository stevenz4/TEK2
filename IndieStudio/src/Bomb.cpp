/*
** EPITECH PROJECT, 2021
** Bomb
** File description:
** Indie Studio
*/

#include "Bomb.hpp"
#include "Player.hpp"

void Bomb::createTimer()
{
    _bombTimer += GetFrameTime();
}

void Bomb::manageBomb(std::vector<GameObject*> &mapObject, std::vector<Player*> &playerObject, Player &player)
{
    static bool explosion = false;

    if (_bomb == true) {
        createTimer();
        if (_bombTimer < 2.5)
            this->display();
       if (_bombTimer >= 2.4 && _bombCreate == false) {
            _bombSound = new music("assets/bomb.mp3");
            _bombCreate = true;
        }
        if (_bombTimer >= 2.5 && explosion == false) {
            manageExplosion(mapObject, playerObject, player);
            explosion = true;
        }
        if (_bombTimer >= 2.5 && _bombTimer < 3.0)
            _bombSound->UpdateMusic();
        if ( _bombTimer >= 3) {
            delete _bombSound;
            _bombCreate = false;
            _bomb = false;
            _bombTimer = 0;
            explosion = false;
        }
    }
}

void Bomb::manageExplosion(std::vector<GameObject*> &mapObject, std::vector<Player*> &playerObject, Player &player)
{
    int posBox = 0;
    int posPlayer = 0;
    BoundingBox bomb = {{this->getPosition().x - (3.0f * _bombRange), this->getPosition().y, this->getPosition().z}, {this->getPosition().x + (3.0f * _bombRange), this->getPosition().y, this->getPosition().z}};
    BoundingBox bomb2 = {{this->getPosition().x, this->getPosition().y, this->getPosition().z - (3.0f * _bombRange)}, {this->getPosition().x, this->getPosition().y, this->getPosition().z + (3.0f * _bombRange)}};
 
    for (Player *i: playerObject) {
        BoundingBox player = {{i->getPosition().x - 1.0f, i->getPosition().y - 1.0f, i->getPosition().z - 1.0f}, {i->getPosition().x + 1.0f, i->getPosition().y + 1.0f, i->getPosition().z + 1.0f}};
        if ((CheckCollisionBoxes(player, bomb) || CheckCollisionBoxes(player, bomb2)) && i->getName() == "Player") {
            _bombSound->playMusic();
            _bombSound->UpdateMusic();
            i->setLife(i->getLife() - 1);
            if (i->getLife() <= 0) {
                delete i;
                playerObject.erase(playerObject.begin() + posPlayer);
                return;
            }
        }
        posPlayer++;
    }
    for (GameObject *i : mapObject) {
        BoundingBox box =  {{i->getPosition().x - 1.5f, i->getPosition().y - 1.0f, i->getPosition().z - 1.5f}, {i->getPosition().x + 1.5f, i->getPosition().y + 1.0f, i->getPosition().z + 1.5f}};
        if ((CheckCollisionBoxes(bomb, box) || CheckCollisionBoxes(bomb2, box)) && i->getName() == "CrateBreakable") {
            _bombSound->playMusic();
            _bombSound->UpdateMusic();
            mapObject.erase(mapObject.begin() + posBox);
            randPowerUp(player);
        }
        posBox++;
    }
}

void Bomb::randPowerUp(Player &player)
{
    int powerUp = rand() % 8 + 1;

    if (powerUp == 1)
        player.setMoveSpeed(player.getMoveSpeed() + 0.01f);
    if (powerUp == 2)
        player.setBombMax(player.getBombMax() + 1);
    if (powerUp == 3)
        this->_bombRange += 1;
}