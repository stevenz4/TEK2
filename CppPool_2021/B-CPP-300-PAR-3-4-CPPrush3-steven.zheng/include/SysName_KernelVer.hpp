/*
** EPITECH PROJECT, 2021
** SysName_KernelVer
** File description:
** Rush 3
*/

#ifndef SYSNAME_KERNELVER_HPP_
#define SYSNAME_KERNELVER_HPP_

#include "IMonitorModule.hpp"

#include <sys/utsname.h>

class SysName_KernelVer : public IMonitorModule {
    public:
        SysName_KernelVer();
        ~SysName_KernelVer();
        bool const &getDisplay() const;
        std::string const &getModuleName() const;
        std::string const &getOsName() const;
        std::string const &getKernelVersion() const;
    protected:
    private:
        std::string _osName;
        std::string _kernelVersion;
        struct utsname _uname;
};

#endif /* !SYSNAME_KERNELVER_HPP_ */
