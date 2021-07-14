/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** test_project.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Toy.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "ConveyorBelt.hpp"
#include "Table.hpp"
#include "Elf.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(toy_object, exit_code, .init=redirect_all_stdout)
{
    Object **obj = MyUnitTests();
    std::cout << (*obj[0]) << std::endl;
    std::cout << (*obj[1]) << std::endl;

    delete obj;

    cr_assert_stdout_eq_str("\
Title : cuddle  /  isTaken : false\n\
Title : happy pony  /  isTaken : false\n", "");
}

Test(teddy, Class_test, .init=redirect_all_stdout)
{
    Teddy teddy("Tibers");
    teddy.getTitle();
    teddy.getIsTaken();
    teddy.isTaken();
    teddy.getIsTaken();
}

Test(pony, Class_test, .init=redirect_all_stdout)
{
    Pony pony("My little pony");
    pony.getTitle();
    pony.getIsTaken();
    pony.isTaken();
    pony.getIsTaken();
}

Test(box, Class_test, .init=redirect_all_stdout)
{
    Object obj("test");
    Object obj2("test1");
    Box boxe("mistery box");
    boxe.wrapMeThat(&obj);
    boxe.CloseMe();
    boxe.wrapMeThat(&obj2);
}

Test(wrap, exit_code, .init=redirect_all_stdout)
{
    Object **obj = new (Object *);
    obj[0] = new Toy("toy");
    obj[1] = new Box("toyBox");
    obj[2] = new GiftPaper("toyPaper");

    Object *obj2 = MyUnitTests(obj);

    delete obj;

    cr_assert_stdout_eq_str("tuuuut tuuut tuut\ntuuuut tuuut tuut\n", "");
}

Test(giftpaper, Class_test, .init=redirect_all_stdout)
{
    Object obj("test");
    Object obj2("test1");
    GiftPaper giftpaper("mistery box");
    giftpaper.wrapMeThat(&obj);
    giftpaper.wrapMeThat(&obj2);
}

Test(create, Class_test, .init=redirect_all_stdout)
{
    IConveyorBelt *cb = createConveyorBelt();
    ITable *table = createTable();
}

Test(PapaXmas, exit_code, .init=redirect_all_stdout)
{
    PapaXmasTable table;
    PapaXmasConveyorBelt cb;

    cb.In();
    cb.In();
    table.Take(11);
    table.Take(4);
    table.put(cb.take());
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    cb.In();
    table.put(cb.take());
    for (int j = 0; j < 10; j++)
        std::cout << table.Look()[j] << std::endl;
    cb.put(table.Take(0));
    cb.put(table.Take(1));
    cb.Out();
    cb.Out();
}

Test(elf, exit_code)
{
    PapaXmasConveyorBelt cb;
    PapaXmasTable table;
    PapaXmasElf elf(&table, &cb);
    Teddy teddy("tibers");
    Box box("mistery box");
    
    elf.PutT();
    elf.PutC();
    elf.IN();
    std::cout << elf.LookC() << std::endl;
    elf.TakeC();
    elf.closeMe();
    elf.openMe();
    elf.PutT();
    for (int j = 0; j < 1; j++)
        std::cout << elf.LookT()[j] << std::endl;
    elf.TakeT(0);
    elf.PutC();
    elf.OUT();
    elf.IN();
    elf.wrapMeThat(&teddy);
    elf.TakeC();
    elf.wrapMeThat(&teddy);
    elf.wrapMeThat(&box);
    elf.IN();
    elf.TakeC();
    elf.wrapMeThat(&teddy);
    elf.wrapMeThat(&box);
    elf.IN();
    elf.TakeC();
    elf.wrapMeThat(&teddy);
    elf.wrapMeThat(&box);
    elf.IN();
    elf.TakeC();
    elf.wrapMeThat(&teddy);
    elf.wrapMeThat(&box);
    elf.IN();
    elf.TakeC();
    elf.wrapMeThat(&teddy);
    elf.wrapMeThat(&box);
}