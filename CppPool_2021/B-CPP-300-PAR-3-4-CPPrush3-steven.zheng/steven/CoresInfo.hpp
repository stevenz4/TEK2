/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** CoresInfo
*/

#ifndef CORESINFO_HPP_
#define CORESINFO_HPP_

#include "IMonitorModule.hpp"
#include <vector>

class CoresInfo : public IMonitorModule{
    public:
        CoresInfo();
        ~CoresInfo();
        float getActivity() const;
        int GetNumberCores() const;
        std::string getModel() const;
        int getActiveFrequency() const;
        int getTotalFrequency() const;
        std::vector<float> getCoreActivity() const;
        bool const &getDisplay() const;
        std::string const &getModuleName() const;
    protected:
    private:
};

#endif /* !CORESINFO_HPP_ */
