/*
** EPITECH PROJECT, 2021
** B-CPP-300-PAR-3-4-CPPrush3-steven.zheng
** File description:
** Ram
*/

#include "Ram.hpp"

Ram::Ram()
{
    this->_moduleName = "Ram";
    this->_display = false;
}

Ram::~Ram()
{
}

bool const &Ram::getDisplay() const
{
    return this->_display;
}

std::string const &Ram::getModuleName() const
{
    return this->_moduleName;
}

float Ram::getRamTotal() 
{
    std::ifstream fileStat("/proc/meminfo");
    std::string line;
    std::string ram;
    float ramTotal;
    fileStat >> ram >> ramTotal;
    return (ramTotal / 1000000);
}

float Ram::getRamUsed()
{
    std::ifstream fileStat("/proc/meminfo");
    std::string line;
    for (;std::getline(fileStat, line) && line.rfind("MemFree", 0););
    line = line.substr(17);
    return (std::stof(line) / 1000000);
}

float Ram::getRamFree()
{
    return (getRamTotal() - getRamUsed());
}

float Ram::getCached()
{
    std::ifstream fileStat("/proc/meminfo");
    std::string line;
    for (;std::getline(fileStat, line) && line.rfind("Cached", 0););
    line = line.substr(17);
    return (std::stof(line) / 1000000);
}


float Ram::Usedpercent()
{
    float percent;

    percent = (getRamUsed() / getRamTotal()) * 100;
    return (percent);
}