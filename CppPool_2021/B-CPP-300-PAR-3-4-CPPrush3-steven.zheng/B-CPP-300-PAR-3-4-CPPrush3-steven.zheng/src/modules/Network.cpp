/*
** EPITECH PROJECT, 2021
** Network
** File description:
** Rush 3
*/

#include "Network.hpp"

Network::Network() : IMonitorModule()
{
    this->_moduleName = "Network";
    this->_display = false;

    std::ifstream file ("/proc/net/dev"), file_bis ("/proc/net/dev");
    std::string line;
    std::string netInfo;
    int bytes_r, packets_r;
    int bytes_t, packets_t;
    int temp;

    getline(file_bis, line);
    getline(file_bis, line);
    while (getline(file_bis, line))
        this->interface_nb = this->interface_nb + 1;
    this->netInter = new network_inter[this->interface_nb + 2];
    getline(file, line);
    for (int j = 0; getline(file, line); j++) {
        file >> this->netInter[j]._interface >> bytes_r >> packets_r >> temp >> temp >> temp >> temp >> temp >> temp;
        file >> bytes_t >> packets_t;
        this->netInter[j].receive.push_back(bytes_r);
        this->netInter[j].receive.push_back(packets_r);
        this->netInter[j].transmit.push_back(bytes_t);
        this->netInter[j].transmit.push_back(packets_t);
        netInfo.append(line + '\n');
    }
}

Network::~Network()
{
}

bool const &Network::getDisplay() const
{
    return this->_display;
}

std::string const &Network::getModuleName() const
{
    return this->_moduleName;
}

void Network::refreshNetInterface()
{
    this->interface_nb = 0;
    delete [] this->netInter;
    std::ifstream file ("/proc/net/dev"), file_bis ("/proc/net/dev");
    std::string line;
    std::string netInfo;
    int bytes_r, packets_r;
    int bytes_t, packets_t;
    int temp;

    getline(file_bis, line);
    getline(file_bis, line);
    while (getline(file_bis, line))
        this->interface_nb = this->interface_nb + 1;
    this->netInter = new network_inter[this->interface_nb + 2];
    getline(file, line);
    for (int j = 0; getline(file, line); j++) {
        file >> this->netInter[j]._interface >> bytes_r >> packets_r >> temp >> temp >> temp >> temp >> temp >> temp;
        file >> bytes_t >> packets_t;
        this->netInter[j].receive.push_back(bytes_r);
        this->netInter[j].receive.push_back(packets_r);
        this->netInter[j].transmit.push_back(bytes_t);
        this->netInter[j].transmit.push_back(packets_t);
        netInfo.append(line + '\n');
    }
}

int Network::getInterfaceNb()
{
    return this->interface_nb;
}