/*
** EPITECH PROJECT, 2021
** FruitBox
** File description:
** Exercise 00
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->_pack = NULL;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits()
{
    FruitNode *tmp = this->_pack;
    int count_node = 0;

    if (tmp == NULL)
        return 0;
    for (; tmp != NULL; count_node++) {
        tmp = tmp->next;
    }
    this->_nbFruits = count_node;
    return this->_nbFruits;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *new_back = new FruitNode;
    FruitNode *tmp = this->_pack;

    if (f == NULL)
        return false;
    if (this->nbFruits() < (this->_size)) {
        if (f == NULL)
            return false;
        new_back->next = NULL;
        new_back->fruit = f;
        if (tmp) {
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = new_back;
        } else
            this->_pack = new_back;
        return true;
    }
    return false;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmp = this->_pack;
    Fruit *fruit = this->_pack->fruit;

    if (this->nbFruits() != 0) {
        this->_pack = tmp->next;
        delete tmp;
        return fruit;
    }
    return NULL;
}

FruitNode *FruitBox::head()
{
    return this->_pack;
}