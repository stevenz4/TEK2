/*
** EPITECH PROJECT, 2021
** Family Matter
** File description:
** Exercise 01
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
    public:
        Character(const std::string &name, int level);
        ~Character();
        enum AttackRange {
            RANGE,
            CLOSE
        };
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        std::string _name;
        int _level;
        int _pv;
        int _energy;
        AttackRange Range;
        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();
        void TakeDamage(int);
    protected:
        std::string _race;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
    private:
};

#endif /* !CHARACTER_HPP_ */
