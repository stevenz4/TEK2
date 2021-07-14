/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include "IMonitorModule.hpp"

class Time : public IMonitorModule {
    public:
        Time();
        ~Time();
        bool const &getDisplay() const;
        std::string const &getModuleName() const;
        void setTime(std::string time);
        std::string const &getTime() const;
        bool refreshTime();
    protected:
    private:
        std::string _time;
};

#endif /* !TIME_HPP_ */
