/*
** EPITECH PROJECT, 2021
** Errors
** File description:
** Exercise 00
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &msg, std::string const &component)
{
    this->_message = msg;
    this->_component = component;
}

MissionCriticalError::MissionCriticalError(std::string const &msg, std::string const &component) : NasaError(msg, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &msg, std::string const &component) : NasaError(msg, component)
{
}

CommunicationError::CommunicationError(std::string const &msg) : NasaError(msg, "CommunicationDevice")
{
}

UserError::UserError(std::string const &msg, std::string const &component) : NasaError(msg, component)
{    
}

std::string const &NasaError::getComponent() const
{
    return this->_component;
}

const char* NasaError::what() const noexcept
{
    return this->_message.c_str();
}