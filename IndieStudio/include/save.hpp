/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#ifndef _SAVE_HPP_
#define _SAVE_HPP_

#include <iostream>
#include <fstream>

class save
{
private:
    int _width;
    int _height;
    int **_map;
    std::string _mapS;
public:
    save(int **map, int width, int height);
    ~save();
    void write_map(std::string path);
    void recup_map(std::string path);
    std::string getMap() {return _mapS;};
};

#endif
