/*
** EPITECH PROJECT, 2021
** FruitBox
** File description:
** Exercise 00
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();
    protected:
    private:
        int _size;
        int _nbFruits;
        FruitNode *_pack;
};

#endif /* !FRUITBOX_HPP_ */
