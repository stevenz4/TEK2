/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Elf
*/

#include "Elf.hpp"

PapaXmasElf::PapaXmasElf(ITable *table, IConveyorBelt *conveyor)
{
    _table = table;
    _converyorBelt = conveyor;
    _object = NULL;
}

PapaXmasElf::~PapaXmasElf()
{
}

bool PapaXmasElf::TakeT(size_t p)
{
    _object = _table->Take(p);
    return (!_object ? false : true);
}

bool PapaXmasElf::PutT()
{
    if (_object != NULL) {
        _table->put(_object);
        _object = NULL;
        return (true);
    }
    else {
        ElfSpeak("I have nothing to put on the table");
        return (false);
    }
}

bool PapaXmasElf::TakeC()
{
    _object = _converyorBelt->take();
    return (!_object ? false : true);
}

bool PapaXmasElf::PutC()
{
    if (_object != NULL) {
        _converyorBelt->put(_object);
        _object = NULL;
        return (true);
    }
    else {
        ElfSpeak("I have nothing to put on the Conveyor");
        return (false);
    }
}

bool PapaXmasElf::wrapMeThat(Object *Object)
{
    if(!_object || !Object)
        return false;
    if (!_object->getType().compare("Box") && Object->getType().compare("Toy"))
        return false;
    if (!_object->getType().compare("GiftPaper") && Object->getType().compare("Box"))
        return false;
    ElfSpeak("I'm packing the gift!");
    return _object->wrapMeThat(Object);
}

void PapaXmasElf::openMe()
{
    _object->OpenMe();
}

void PapaXmasElf::closeMe()
{
    _object->CloseMe();
}

void PapaXmasElf::IN()
{
    _converyorBelt->In();
}

void PapaXmasElf::OUT()
{
    _converyorBelt->Out();
}

const std::string *PapaXmasElf::LookT()
{
    return _table->Look();
}

const std::string PapaXmasElf::LookC()
{
    return _converyorBelt->Look();
}