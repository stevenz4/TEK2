/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "CoresInfo.hpp"

CoresInfo::CoresInfo()
{
    this->_moduleName = "CoresInfo";
    this->_display = false;
}

CoresInfo::~CoresInfo()
{
}

float CoresInfo::getActivity() const
{
    std::ifstream fileStat("/proc/stat");
    std::string line;
    std::string cpu;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    float active;
    float inactive;
    float percent;
    fileStat >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
    active = user + nice + system + irq + softirq + steal;
    inactive = active + idle + iowait;
    percent = 100 * (active / inactive);
    return (percent);
}

int CoresInfo::GetNumberCores() const
{
    std::ifstream fileStat("/proc/stat");
    std::string line;
    std::getline(fileStat, line);
    int i = 0;
    while (std::getline(fileStat, line) && !line.rfind("cpu", 0))
    {
        i++;
    }
    return (i);
}

std::string CoresInfo::getModel() const
{
    std::ifstream fileStat("/proc/cpuinfo");
    std::string line;
    std::getline(fileStat, line);
    std::string model;
    for (;std::getline(fileStat, line) && line.rfind("model name", 0););
    line = line.substr(13);
    return (line);
}

int CoresInfo::getActiveFrequency() const
{
    std::ifstream fileStat("/proc/stat");
    std::string line;
    std::string cpu;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    float active;
    float percent;
    fileStat >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
    active = user + nice + system + irq + softirq + steal;
    return (active);
}

int CoresInfo::getTotalFrequency() const
{
    std::ifstream fileStat("/proc/stat");
    std::string line;
    std::string cpu;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    float active;
    float total;
    float percent;
    fileStat >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
    active = user + nice + system + irq + softirq + steal;
    total = active + idle + iowait;
    return (total);
}

std::vector<float> CoresInfo::getCoreActivity() const
{
    std::vector<float> vec;
    std::ifstream fileStat("/proc/stat");
    std::string cpu;
    std::string line;
    int user, nice, system, idle, iowait, irq, softirq, steal;
    float active;
    float inactive;
    float percent;
    std::getline(fileStat, line);
    for (int i = 0; i != GetNumberCores(); i++) {
        fileStat >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
        active = user + nice + system + irq + softirq + steal;
        inactive = active + idle + iowait;
        percent = 100 * (active / inactive);
        vec.push_back(percent);
        std::getline(fileStat, line);
    }
    return (vec);
}

bool const &CoresInfo::getDisplay() const
{
    return this->_display;
}

std::string const &CoresInfo::getModuleName() const
{
    return this->_moduleName;
}