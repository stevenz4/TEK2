/*
** EPITECH PROJECT, 2021
** PIcture
** File description:
** Exercise 00
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Picture {
    public:
        Picture(const std::string &file);
        Picture(Picture const &copy);
        Picture();
        ~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(Picture const &);
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
