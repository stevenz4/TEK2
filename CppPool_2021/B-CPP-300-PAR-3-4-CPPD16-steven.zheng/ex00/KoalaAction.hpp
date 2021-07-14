/*
** EPITECH PROJECT, 2021
** ka
** File description:
** ka
*/

#ifndef KOALAACTION_HPP_
#define KOALAACTION_HPP_

#include <string>
#include <iostream>
#include <vector>

class KoalaAction {
    public :
        KoalaAction() {};
        ~KoalaAction() {};
        void eat (const std::string &);
        void goTo (const std::string &);
        void sleep (const std::string &);
        void reproduce (const std::string &);
    private :
};

#endif /* !KOALAACTION_HPP_ */
