/*
** EPITECH PROJECT, 2021
** Borg
** File description:
** Exercise 01 include
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "Federation.hpp"

namespace Federation
{   
    namespace Starfleet
    {
        class Ship;
        class Captain;
        class Ensign;
    };
    class Ship;
};

namespace WarpSystem {
    class QuantumReactor;
    class Core;
}
namespace Borg {

    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int _shield;
            int _weaponFrequency;
            int _repair;
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *);
            void fire(Federation::Ship *);
            void repair();
        protected:
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core_;
            Destination _location;
            Destination _home;
    };
}
#endif
