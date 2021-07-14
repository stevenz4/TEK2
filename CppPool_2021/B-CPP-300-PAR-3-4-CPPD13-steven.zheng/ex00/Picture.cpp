/*
** EPITECH PROJECT, 2021
** Picture
** File description:
** Exercise 00
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data.clear();
}

Picture::Picture(const std::string &file)
{
    if (file.empty()) {
        this->data.clear();
        return;
    }
    this->getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::stringstream content;
    std::ifstream my_file(file);

    if (my_file.is_open()) {
        content << my_file.rdbuf();
        my_file.close();
        this->data = content.str();
    } else {
        this->data = "ERROR";
        return false;
    }
    return true;
}

Picture &Picture::operator=(Picture &picture)
{
    this->data = picture.data;
    return *this;
}