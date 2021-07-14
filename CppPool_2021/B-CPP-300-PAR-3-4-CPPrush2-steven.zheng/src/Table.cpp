/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Table.cpp
*/

#include "Table.hpp"

PapaXmasTable::PapaXmasTable() : ITable::ITable()
{
    for (int i = 0; i < 10; i++)
        objTab[i] = NULL;
}

Object *PapaXmasTable::Take(size_t i)
{
  Object	*ret;
  if (i >= 10)
    {
        ElfSpeak("Not on the table");
        return NULL;
    }
  if (objTab[i])
    {
        ElfSpeak(objTab[i]->getTitle() + " was taken from the table at pos " + std::to_string(i));
        ret = objTab[i];
        objTab[i] = NULL;
        return ret;
    }
    ElfSpeak("pos " + std::to_string(i) + " is empty...");
    return NULL;
}

bool PapaXmasTable::put(Object *newObj)
{
    if (!newObj)
        return false;
    for (int i = 0; i < 10; i++) {
        if (!objTab[i]) {
            objTab[i] = newObj;
            ElfSpeak("I Put the " + newObj->getTitle() + " on the Table");
            return true;
        }
    }
    ElfSpeak("Hoho, the table collapses..");
    return false;
}

std::string *PapaXmasTable::Look()
{
    std::string *ret = new std::string[10];
    int		j = 0;

    for (int i = 0; i < 10; i++) {
        if (objTab[i]) {
            ret[j] = objTab[i]->getTitle();
            j++;
        }
    }
  return ret;
}

void ElfSpeak(std::string message) {
	std::cout << "Elf: " << message << std::endl;
}

ITable *createTable()
{
  return new PapaXmasTable;
}