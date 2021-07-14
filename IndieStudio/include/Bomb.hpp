/*
** EPITECH PROJECT, 2021
** Bomb
** File description:
** Indie Studio
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_


#include "GameObject.hpp"
#include "Music.hpp"
#include <vector>

class Player;

class Bomb : public GameObject {
    public:
        Bomb(std::string const &name, Vector3 position, Model const &model) 
        : GameObject(name, position, model, "", "") {_bomb = true; _bombCreate = false; _bombRange = 1;};
        void createTimer();
        void manageBomb(std::vector<GameObject*> &mapObject, std::vector<Player*> &playerObject, Player &player);
        void manageExplosion(std::vector<GameObject*> &mapObject, std::vector<Player*> &playerObject, Player &player);
        void randPowerUp(Player &player);
        bool getBombPosed() const {return _bomb;};
        void setBombPosed(bool status) {_bomb = status;};
        const int &getBombRange() {return _bombRange;};
    protected:
    private:
        int _bombRange;
        bool _bomb;
        bool _bombCreate;
        float _bombTimer;
        music *_bombSound;
};

#endif /* !BOMB_HPP_ */
