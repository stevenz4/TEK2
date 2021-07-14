/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "save.hpp"
#include "Load_map.hpp"
#include "Exception.hpp"

void save::recup_map(std::string path)
{
    std::ifstream try_path(musicName);
    if (!try_path)
        throw fdne_ex;
    try_path.close();
    std::ifstream file(path);
    if (!file)
        return ;
    std::string input;
    int width = 0;
    int height = 0;
    while (file >> input) {
        _mapS = _mapS + input + '\n';
        if (width == 0)
            height = input.length();
        width++;
    }
}

void save::write_map(std::string path)
{
    std::ofstream fd(path);
    int o = 0;
    int i = 0;
    for (; i < _width; o++) {
        if (o < _height)
            fd << _map[i][o];
        else {
            fd << std::endl;
            i++;
            o = -1;
        }
    }
}

save::save(int **map, int width, int height)
{
    _width = width;
    _height = height;
    _map = map;
}

save::~save()
{

}
