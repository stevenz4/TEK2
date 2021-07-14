/*
** EPITECH PROJECT, 2021
** ka
** File description:
** ka
*/

#include "KoalaAction.hpp"

void KoalaAction::eat (const std::string &text)
{
    std::cout << "I eat: " << text << std::endl;
}

void KoalaAction::goTo (const std::string &text)
{
    std::cout << "I go: " << text << std::endl;
}

void KoalaAction::sleep (const std::string &text)
{
    std::cout << "I sleep, and dream of: " << text << std::endl;
}

void KoalaAction::reproduce (const std::string &text)
{
    std::cout << "I attempt to reproduce with: " << text << std::endl;
}