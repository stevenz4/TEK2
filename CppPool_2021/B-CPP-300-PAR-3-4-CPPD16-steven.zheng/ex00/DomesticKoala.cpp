/*
** EPITECH PROJECT, 2021
** DomesticKoala
** File description:
** Exercise 00
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action)
{
    this->_listAction = action;
}

DomesticKoala::DomesticKoala(const DomesticKoala &copy)
{
    this->_listAction = copy._listAction;
    this->_vector_act_cmd = copy._vector_act_cmd;
    this->_vector_action = copy._vector_action;
}

DomesticKoala::~DomesticKoala()
{
}


void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    this->_vector_act_cmd.push_back(command);
    this->_vector_action.push_back(action);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    for (long unsigned int j = 0; j < this->_vector_act_cmd.size(); j++)
        if (command == this->_vector_act_cmd[j])
            (this->_listAction.*_vector_action[j])(param);    
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    std::vector<methodPointer_t>::iterator it;
    std::vector<unsigned char>::iterator it2;

    for (long unsigned int j = 0; j < this->_vector_act_cmd.size(); j++) {
        if (command == this->_vector_act_cmd[j]) {
            it = this->_vector_action.begin() + j;
            it2 = this->_vector_act_cmd.begin() + j;
            this->_vector_action.erase(it);
            this->_vector_act_cmd.erase(it2);
        }
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    this->_listAction = action;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &copy)
{
    this->_listAction = copy._listAction;
    this->_vector_act_cmd = copy._vector_act_cmd;
    this->_vector_action = copy._vector_action;
    return (*this);
}