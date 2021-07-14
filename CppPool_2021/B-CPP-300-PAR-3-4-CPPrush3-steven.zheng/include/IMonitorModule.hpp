/*
** EPITECH PROJECT, 2021
** IMonitorModule
** File description:
** Rush3
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>
#include <string>

class IMonitorModule {
    public:
        IMonitorModule() {};
        virtual ~IMonitorModule() {};
        virtual bool const &getDisplay() const = 0;
        virtual std::string const &getModuleName() const = 0;
    protected:
        bool _display;
        std::string _moduleName;
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
