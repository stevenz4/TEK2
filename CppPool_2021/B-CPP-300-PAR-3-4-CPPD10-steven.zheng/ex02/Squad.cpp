/*
** EPITECH PROJECT, 2021
** Squad
** File description:
** Exercise 02
*/

#include "Squad.hpp"

Squad::Squad()
{
    this->_count = 0;
    this->_array = new ISpaceMarine*[20];
    for (int j = 0; j < 20; j++)
        this->_array[j] = NULL;
}

Squad::Squad(Squad const &copy)
{
    for (int j = 0; j < copy.getCount(); j++) {
        this->_array[j] = NULL;
        if (copy._array[j])
            this->_array[j] = copy._array[j]->clone();
    }
}

Squad::~Squad() 
{
    for (int j = 0; j < this->_count; j++)
        delete(this->_array[j]);
    delete _array;
}

int Squad::countSquad()
{
    int  j = 0;

    for (; this->_array[j] != NULL; j++);

    this->_count = j;
    return this->_count;
}

int Squad::getCount() const
{
    return this->_count;
}

ISpaceMarine *Squad::getUnit(int index)
{
    this->countSquad();
    if (index > 20 || index < 0)
        return NULL;
    return this->_array[index];
}

int Squad::push(ISpaceMarine *sm)
{
    if (sm) {
        this->countSquad();
        this->_array[this->_count] = sm;
    }
    return this->_count;
}