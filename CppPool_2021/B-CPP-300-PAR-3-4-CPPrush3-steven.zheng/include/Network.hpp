/*
** EPITECH PROJECT, 2021
** Network
** File description:
** Rush 3
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "IMonitorModule.hpp"

#include <fstream>
#include <sstream>
#include <vector>

typedef struct network_info_st {
    std::string _interface;
    std::vector<long long int> receive;
    std::vector<long long int> transmit;
} network_inter;

class Network : public IMonitorModule {
    public:
        Network();
        ~Network();
        bool const &getDisplay() const;
        std::string const &getModuleName() const;
        void refreshNetInterface();
        network_inter *netInter;
        int getInterfaceNb();
    private:
        int interface_nb = 0;
};

#endif /* !NETWORK_HPP_ */
