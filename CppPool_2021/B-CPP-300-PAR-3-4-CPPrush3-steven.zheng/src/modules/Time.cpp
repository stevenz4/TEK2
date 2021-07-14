/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Time
*/

#include "Time.hpp"

Time::Time()
{
    this->_moduleName = "Time";
    this->_display = false;
}

Time::~Time()
{
}

bool const &Time::getDisplay() const
{
    return this->_display;
}

std::string const &Time::getModuleName() const
{
    return this->_moduleName;
}

void Time::setTime(std::string time)
{
    this->_time = time;
}

std::string const &Time::getTime() const
{
    return (this->_time);
}

bool Time::refreshTime()
{
    auto start = std::chrono::system_clock::now();
    std::time_t _timeNow = std::chrono::system_clock::to_time_t(start);
    _time = std::ctime(&_timeNow);
    _time.erase(std::remove(_time.begin(), _time.end(), '\n'), _time.end());
    return (true);
}