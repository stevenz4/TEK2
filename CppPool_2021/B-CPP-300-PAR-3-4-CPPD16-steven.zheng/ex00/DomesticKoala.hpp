/*
** EPITECH PROJECT, 2021
** DomesticKoala
** File description:
** Exercise 00
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <string>
#include <iostream>
#include <vector>

#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &);
        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);
        ~DomesticKoala();
        using methodPointer_t = void (KoalaAction::*) (const std::string &);
        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);
    protected:
    private:
        KoalaAction _listAction;
        std::vector<methodPointer_t> _vector_action;
        std::vector<unsigned char> _vector_act_cmd;
};

#endif /* !DOMESTICKOALA_HPP_ */
