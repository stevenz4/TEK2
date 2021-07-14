/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Motion.hpp"
#include "Bomb.hpp"
#include <ctime>
#include <list>
#include <vector>

class Player : public Motion {
    public:
        Player(int p, bool ia, int id, std::string const &name, Vector3 position, std::string const &modelpath, std::string const &texturepath, std::string const &animpath = "") 
        : Motion(name, position, modelpath, texturepath, animpath) {_id = id; _Ia = ia; _P = p; _life = 3; _bombNb = 2; _bombMax = 2; _moveSpeed = 0.1f; for (int j = 0; j < _bombNb; j++)
        _bomb.push_back(new Bomb("Bomb", {0.0f, 0.0f, 0.0f}, LoadModelFromMesh(GenMeshSphere(1, 15, 15))));}
        void plantBomb();
        void manageBomb(std::vector<GameObject*> &mapObject, std::vector<Player*> &playerObject, Player &player);
        void input(const std::vector<GameObject*> &_mapObject);
        bool checkCollision(Dir dir, const std::vector<GameObject*> &_mapObject);
        void input(bool ia, const std::vector<GameObject*> &_mapObject);
        const int &getId() {return _id;};
        const int &getLife() {return _life;};
        const bool &getIa() {return _Ia;};
        const float &getMoveSpeed() {return _moveSpeed;};
        const int &getBomb() {return _bombNb;};
        const int &getBombMax() {return _bombMax;};
        const int &getBombRange() {return _bomb.at(0)->getBombRange();};
        void setMoveSpeed(float moveSpeed) {_moveSpeed = moveSpeed;};
        void setLife(int life) {_life = life;};
        void setBombMax(int bombMax) {_bombMax = bombMax;};
        Dir dir;
        Dir bf_dir;
    private:
        int _id;
        float _moveSpeed;
        int _life;
        int _bombNb;
        std::clock_t _clock = std::clock();
        int _bombMax;
        bool _Ia;
        int _P;
        std::vector<Bomb*> _bomb;
};

#endif /* !PLAYER_HPP_ */