/*
** EPITECH PROJECT, 2021
** SysName_KernelVer
** File description:
** Rush 3
*/

#include "SysName_KernelVer.hpp"

SysName_KernelVer::SysName_KernelVer() : IMonitorModule()
{
    this->_moduleName = "SysName_KernelVer";
    this->_display = false;
    if (uname(&this->_uname) == 0) {
        this->_osName = this->_uname.sysname;
        this->_kernelVersion = this->_uname.version;
    }
}

SysName_KernelVer::~SysName_KernelVer()
{
}

bool const &SysName_KernelVer::getDisplay() const
{
    return this->_display;
}

std::string const &SysName_KernelVer::getModuleName() const
{
    return this->_moduleName;
}

std::string const &SysName_KernelVer::getOsName() const
{
    return this->_osName;
}

std::string const &SysName_KernelVer::getKernelVersion() const
{
    return this->_kernelVersion;
}
