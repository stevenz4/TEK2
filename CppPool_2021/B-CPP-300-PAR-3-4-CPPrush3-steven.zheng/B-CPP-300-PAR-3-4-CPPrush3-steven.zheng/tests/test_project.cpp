/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** test_project.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(toy_object, exit_code, .init=redirect_all_stdout)
{

    cr_assert_stdout_eq_str("\
Title : cuddle  /  isTaken : false\n\
Title : happy pony  /  isTaken : false\n", "");
}