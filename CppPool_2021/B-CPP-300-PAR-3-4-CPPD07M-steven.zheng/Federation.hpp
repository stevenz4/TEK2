/*
** EPITECH PROJECT, 2021
** Federation
** File description:
** Exercise 00, Federation.hpp
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_
#include "Destination.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include <iostream>
#include <cstring>
#include <string>

namespace WarpSystem {
    class QuantumReactor;
    class Core;
}

namespace Borg {
    class Ship;
}
namespace Federation {
    namespace Starfleet {
        class Ensign {
            public :
                Ensign(std::string name);
                ~Ensign();
            private :
                std::string _name;
        };
        class Captain {
            public :
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
            private :
                std::string name;
                int _age;
        };
        class Ship {
            public:
                Ship(int length , int width, std::string name, short maxWarp, int torpedo);
                Ship(int length , int width, std::string name, short maxWarp);
                Ship();
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
                int _shield;
                int _photoTorpedo;
                Captain *_captain;
            protected:
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
        };
    }
    class Ship {
        public:
            Ship(int length , int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();
            WarpSystem::Core *_core_;
        protected:
        private:
            int _length_;
            int _width_;
            std::string _name_;
            Destination _location;
            Destination _home;
        };
}

#endif