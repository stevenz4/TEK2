/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Elf
*/

#ifndef ELF_HPP_
#define ELF_HPP_

#include <iostream>
#include <string>
#include "Table.hpp"
#include "ConveyorBelt.hpp"
#include "Object.hpp"
#include "Wrap.hpp"
#include "Toy.hpp"

using namespace std;

class IElf
{
protected:
    virtual bool TakeT(size_t) = 0;
    virtual bool PutT() = 0;
    virtual bool TakeC() = 0;
    virtual bool PutC() = 0;
    virtual bool wrapMeThat(Object *) = 0;
	virtual void openMe() = 0;
	virtual void closeMe() = 0;
	virtual void IN() = 0;
	virtual void OUT() = 0;
    virtual const string *LookT() = 0;
    virtual const string LookC() = 0;
};

class PapaXmasElf : public IElf
{
protected:
    ITable *_table;
    IConveyorBelt *_converyorBelt;
    Object *_object;

public:
    PapaXmasElf(ITable *, IConveyorBelt *);
    ~PapaXmasElf();
    bool TakeT(size_t);
    bool PutT();
    bool TakeC();
    bool PutC();
    bool wrapMeThat(Object *);
	void openMe();
	void closeMe();
	void IN();
	void OUT();
	const std::string *LookT();
	const std::string LookC();
};
#endif