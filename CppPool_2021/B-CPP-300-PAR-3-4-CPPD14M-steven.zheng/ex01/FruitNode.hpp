/*
** EPITECH PROJECT, 2021
** FruitNode
** File description:
** Exercise 00
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "FruitNode.hpp"
#include "Fruit.hpp"

typedef struct FruitNode {
    Fruit *fruit;
    struct FruitNode *next;
} FruitNode;

#endif /* !FRUITNODE_HPP_ */
