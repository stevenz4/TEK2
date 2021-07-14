/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** LoadMap
*/

#include "LoadMap.hpp"

void Map::check_corner()
{
    _map[1][1] = 1;
    _map[1][2] = 1;
    _map[2][1] = 1;
    _map[1][_height - 2] = 1;
    _map[1][_height - 3] = 1;
    _map[2][_height - 2] = 1;
    _map[_width - 2][1] = 1;
    _map[_width - 3][1] = 1;
    _map[_width - 2][2] = 1;
    _map[_width - 2][_height - 2] = 1;
    _map[_width - 3][_height - 2] = 1;
    _map[_width - 2][_height - 3] = 1;

}

void Map::generate_box()
{
    for (int i = 0; i < _width; i++) {
        for (int o = 0; o < _height; o++) {
            if (_map[i][o] == 1) {
                int nbr = rand()%2;
                if (nbr == 1)
                    _map[i][o] = 3;
            }
        }
    }
}

void Map::generate_map()
{
    for (int i = 0; i < _width; i++) {
        for (int o = 0; o < _height; o++) {
            if (i == 0 || i == _width - 1)
                _map[i][o] = 0;
            else if (o % 2 == 0 && i % 2 == 0)
                _map[i][o] = 0;
            else {
                if (o == 0 || o == _height - 1)
                    _map[i][o] = 0;
                else 
                    _map[i][o] = 1;
            }
        }
    }
}

void Map::set_map_size()
{
    switch (_size) {
        case SMALL:
            _width = 13;
            _height = 9;
            break;
        case MEDIUM:
            _width = 21;
            _height = 15;
            break;
        case LARGE:
            _width = 31;
            _height = 23;
            break;
    }
}

Map::Map(const MapSize &size)
{
    _size = size;
    set_map_size();
    _map = new int*[_width];
    for (int i = 0; i < _width; i++)
        _map[i] = new int[_height];
    generate_map();
    generate_box();
    check_corner();
}

Map::~Map()
{
    for (int i = 0; i < _width; i++)
        delete [] _map[i];
    delete [] _map;
}