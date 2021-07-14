/*
** EPITECH PROJECT, 2021
** TableRand
** File description:
** Rush2
*/

#include "TableRand.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

TableRand::TableRand() : PapaXmasTable()
{
    int rand_nb = 0;

    for (int j = 0; j < 10; j++) {
        rand_nb = rand() % 4;
        if (rand_nb == 0)
            this->objTab[j] = new GiftPaper("GiftPaper");
        if (rand_nb == 1)
            this->objTab[j] = new Box("Box");
        if (rand_nb == 2)
            this->objTab[j] = new Pony("happy pony");
        if (rand_nb == 3)
            this->objTab[j] = new Teddy("little bear");
    }
}

TableRand::~TableRand()
{
    for (int j = 0; j < 10 ; j++) {
        if (this->objTab[j])
            delete this->objTab[j];
    }
}