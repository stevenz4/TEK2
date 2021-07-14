/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ConveyorBelt.hpp
*/

#ifndef CONVOEYORBELT_HPP_
#define CONVOEYORBELT_HPP_

#include "Wrap.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

class IConveyorBelt {
    public:
        virtual bool put(Object *object) = 0;
        virtual Object *take() = 0;
        virtual Object *In() = 0;
        virtual bool Out() = 0;
        std::string Look() {return (object->getTitle());};
    protected :
        Object *object;
    private :
};

class PapaXmasConveyorBelt : public IConveyorBelt {
    public :
        PapaXmasConveyorBelt();
        virtual ~PapaXmasConveyorBelt();
        Object *In();
        bool Out();
        bool put(Object *object);
        Object *take();
    protected :
    private :
        int _rand = 0;
};

IConveyorBelt *createConveyorBelt();
void ElfSpeak(std::string message);

#endif

