/*
** EPITECH PROJECT, 2021
** Hostname_Username
** File description:
** Rush 3
*/

#ifndef HOSTNAME_USERNAME_HPP_
#define HOSTNAME_USERNAME_HPP_

#include "IMonitorModule.hpp"

#include <unistd.h>
#include <limits.h>

class Hostname_Username : public IMonitorModule {
    public:
        Hostname_Username();
        ~Hostname_Username();
        bool const &getDisplay() const;
        std::string const &getModuleName() const;
        std::string const &getHostname() const;
        std::string const &getUsername() const;
        void refreshHostname();
        void refreshUsername();
    protected:
    private:
        std::string hostname;
        std::string username;
};

#endif /* !HOSTNAME_USERNAME_HPP_ */
