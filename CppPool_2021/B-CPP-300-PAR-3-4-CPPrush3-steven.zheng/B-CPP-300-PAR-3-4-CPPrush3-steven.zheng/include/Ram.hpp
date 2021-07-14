/*
** EPITECH PROJECT, 2021
** B-CPP-300-PAR-3-4-CPPrush3-steven.zheng
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "IMonitorModule.hpp"
#include <fstream>

class Ram : public IMonitorModule
{
    public:
        Ram();
        ~Ram();

        float getRamTotal();
        float getRamFree();
        float getRamUsed();
        float getCached();
        float Usedpercent();
        bool const &getDisplay() const;
        std::string const &getModuleName() const;

    protected:
        std::string _Ram;

    private:
};

#endif /* !RAM_HPP_ */
