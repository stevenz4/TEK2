/*
** EPITECH PROJECT, 2021
** Core 
** File description:
** Rush 3
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "CoresInfo.hpp"
#include "Hostname_Username.hpp"
#include "Network.hpp"
#include "Ram.hpp"
#include "SysName_KernelVer.hpp"
#include "Time.hpp"

enum displayType {
    SFML,
    NCURSES,
};

class Core {
    public:
        Core(displayType);
        ~Core();
        CoresInfo _cores;
        Hostname_Username _hostname_username;
        Network _network;
        //Ram _ram;
        SysName_KernelVer _sysName_kernelVer;
        Time _time;
        displayType _typeDisplay;
    protected:
    private:
};

#endif /* !CORE_HPP_ */
