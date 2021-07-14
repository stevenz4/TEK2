/*
** EPITECH PROJECT, 2021
** WarpSystem
** File description:
** Exercise 00
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *core)
{
    _coreReactor = core;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}

WarpSystem::Core::~Core()
{
}