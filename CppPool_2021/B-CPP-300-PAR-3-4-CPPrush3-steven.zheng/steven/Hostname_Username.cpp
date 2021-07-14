/*
** EPITECH PROJECT, 2021
** Hostname_Username
** File description:
** Rush 3
*/

#include "Hostname_Username.hpp"

Hostname_Username::Hostname_Username() : IMonitorModule()
{
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    std::string temp_hostname (hostname);
    std::string temp_username (username);

    this->_moduleName = "Hostname_Username";
    this->_display = false;
    this->hostname = temp_hostname;
    this->username = temp_username;
}

Hostname_Username::~Hostname_Username()
{
}

bool const &Hostname_Username::getDisplay() const
{
    return this->_display;
}

std::string const &Hostname_Username::getModuleName() const
{
    return this->_moduleName;
}

std::string const &Hostname_Username::getHostname() const
{
    return this->hostname;
}

std::string const &Hostname_Username::getUsername() const
{
    return this->username;
}

void Hostname_Username::refreshHostname()
{
    char hostname[HOST_NAME_MAX];

    gethostname(hostname, HOST_NAME_MAX);
    std::string temp_hostname (hostname);
    this->hostname = temp_hostname;
}

void Hostname_Username::refreshUsername()
{
    char username[LOGIN_NAME_MAX];

    getlogin_r(username, LOGIN_NAME_MAX);
    std::string temp_username (username);
    this->username = temp_username;
}

