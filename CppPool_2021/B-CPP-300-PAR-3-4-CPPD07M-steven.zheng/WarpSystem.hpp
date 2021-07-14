/*
** EPITECH PROJECT, 2021
** WarpSystem include
** File description:
** Exercise 00
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

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
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);

        protected:
        private:
            bool _stability;
    };
    class Core {
        public:
            Core(QuantumReactor *);
            ~Core();
            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif
