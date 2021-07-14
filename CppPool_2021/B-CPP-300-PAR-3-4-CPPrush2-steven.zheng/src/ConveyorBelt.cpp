/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ConveyorBelt.cpp
*/

#include "ConveyorBelt.hpp"
#include "Table.hpp"
#include <time.h>

IConveyorBelt *createConveyorBelt()
{
    return new PapaXmasConveyorBelt;
}

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    this->object = NULL;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt() {}

Object *PapaXmasConveyorBelt::In()
{
    srand(time(NULL) + _rand++);
    int random_nb = random() % 2;

    if (this->object) {
        ElfSpeak("There is already an Object on the Conveyor Belt");
        return NULL;
    }
    if (random_nb == 0)
        this->object = new GiftPaper("GiftPaper");
    else 
        this->object = new Box("Box");
    return object;
}

bool PapaXmasConveyorBelt::Out()
{
    if (!this->object) {
        ElfSpeak("There is nothing on the Conveyor Belt");
        return false;
    }
    ElfSpeak(this->object->getTitle() + " has been sent to Santa");
    this->object = NULL;
    return true;
}

bool PapaXmasConveyorBelt::put(Object *object)
{
    if (this->object) {
        ElfSpeak("There is already " + this->object->getTitle() + " on the Conveyor Belt");
        return false;
    } else {
        this->object = object;
        ElfSpeak("I put the " + this->object->getTitle() + " on the Conveyor Belt");
        return true;
    }
    return false;
}

Object *PapaXmasConveyorBelt::take()
{
    Object *ret;

    if (this->object) {
        ElfSpeak("I'm taking the " + this->object->getTitle() + " from the Conveyor Belt");
        ret = this->object;
        this->object = NULL;
        return ret;
    }
    ElfSpeak("There is nothing on the Conveyor Belt");
    return NULL;
}