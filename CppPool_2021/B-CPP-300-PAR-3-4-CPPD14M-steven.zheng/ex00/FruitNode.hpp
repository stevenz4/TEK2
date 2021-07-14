/*
** EPITECH PROJECT, 2021
** FruitNode
** File description:
** Exercise 00
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public :
        Fruit *fruit;
        struct FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
