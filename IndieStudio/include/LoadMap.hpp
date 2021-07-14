/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** LoadMap
*/

#ifndef _LOADMAP_HPP_
#define _LOADMAP_HPP_

#include <iostream>

typedef enum MapSize
{
    SMALL,
    MEDIUM,
    LARGE
} MapSize;

class Map {
    public:
        Map(const MapSize &map);
        ~Map();
        void generate_map();
        void generate_box();
        void check_corner();
        void set_map_size();
        int **get_map() {return _map;};
        int get_width() {return _width;};
        int get_height() {return _height;};
    private:
        int **_map;
        int _width;
        int _height;
        int _size;
};

#endif