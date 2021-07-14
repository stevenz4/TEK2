/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** test_project.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <memory>
#include "../ex04/Toy.hpp"
#include "../ex04/Picture.hpp"
#include "../ex04/Buzz.hpp"
#include "../ex04/Woody.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(toy, output_check, .init=redirect_all_stdout)
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "./alien.txt");
    toto.setName("TOTO !");
    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl << ET.getAscii() << std::endl;
}

Test(toy2, exit_code, .init=redirect_all_stdout)
{
    std::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody ("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "./alien.txt"));
    b->speak("To the code, and beyond!!!!!!!!");
    w->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");

    cr_assert_stdout_eq_str("\
BUZZ: buzziiiii \"To the code, and beyond!!!!!!!!\"\n\
WOODY: wood \"There's a snake in my boot.\"\n\
ET \"the claaaaaaw\"\n", "");
}

Test(toy3, exit_code, .init=redirect_all_stdout)
{
    Toy a(Toy::BASIC_TOY, "REX", "./rex.txt");
    std::cout << a;
    a << "\\o/";
    std::cout << a;
}