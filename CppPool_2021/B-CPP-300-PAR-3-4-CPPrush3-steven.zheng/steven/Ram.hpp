/*
** EPITECH PROJECT, 2021
** B-CPP-300-PAR-3-4-CPPrush3-steven.zheng
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "IMonitorModule.hpp"

class Ram : public IMonitorModule
{
    public:
        Ram();
        ~Ram();

        void setRam(bool);
        bool refreshRam();

    protected:
    private:
};

#endif /* !RAM_HPP_ */
