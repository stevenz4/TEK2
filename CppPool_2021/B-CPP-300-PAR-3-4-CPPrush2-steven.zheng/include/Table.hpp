/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Table.hpp
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_

#include "string"
#include "fstream"
#include "ostream"
#include "Object.hpp"

class ITable
{
    public:
        virtual bool put(Object *) = 0;
        virtual Object *Take(size_t) = 0;
        virtual std::string *Look() = 0;
    protected :
};

class PapaXmasTable : public ITable
{
    private:
    protected:
        Object *objTab[10];
    public:
        PapaXmasTable();
        Object *Take(size_t);
        bool put(Object *);
        std::string *Look();
};

void ElfSpeak(std::string message);
ITable *createTable();

#endif