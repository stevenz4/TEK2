/*
** EPITECH PROJECT, 2021
** AEnemy
** File description:
** Exercise 01
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>
#include <iostream>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();
        virtual void takeDamage(int damage);
        std::string getType() const;
        int getHP() const;
    protected:
        int _hp;
        std::string _type;
    private:
};

#endif /* !AENEMY_HPP_ */
