/*
** EPITECH PROJECT, 2021
** SFML Class
** File description:
** Rush 3
*/

#include "sfml.hpp"

SFML_c::SFML_c(Core core) : IMonitorDisplay(), _core(core)
{
    this->_mode.height = HEIGHT;
    this->_mode.width = WIDTH;
    this->wallpaper.texture.loadFromFile("assets/wallpaper.jpg");
    this->wallpaper.sprite.setTexture(this->wallpaper.texture);
    this->_font.loadFromFile("assets/Roboto-Medium.ttf");
    this->CPU_zone.setSize(sf::Vector2f(WIDTH - 20, (HEIGHT - 80)/6));
    this->CPU_zone.setFillColor(sf::Color::White);
    this->CPU_zone.setOutlineThickness(10);
    this->CPU_zone.setOutlineColor(sf::Color::Blue);
    this->cpu_cores = new sf::Text[this->_core._cores.GetNumberCores()];
    this->cpu_core_separator = new sf::RectangleShape[this->_core._cores.GetNumberCores() + 1];
    for (int j = 0; j < this->_core._cores.GetNumberCores() + 1; j++) {
        this->cpu_core_separator[j].setSize(sf::Vector2f(5, (HEIGHT - 80)/6));
        this->cpu_core_separator[j].setFillColor(sf::Color::Black);
    }
    this->cpu_graph.setPointCount(12);
    this->cpu_graph.setOutlineThickness(1);
    this->cpu_graph.setOutlineColor(sf::Color::Black);
    this->cpu_graph.setFillColor(sf::Color::Blue);

    this->ram_graph.setPointCount(12);
    this->ram_graph.setOutlineThickness(1);
    this->ram_graph.setOutlineColor(sf::Color::Black);
    this->ram_graph.setFillColor(sf::Color::Blue);
    
    this->RAM_zone.setSize(sf::Vector2f(WIDTH-20, (HEIGHT - 80) / 6));
    this->RAM_zone.setFillColor(sf::Color::White);
    this->RAM_zone.setOutlineThickness(10);
    this->RAM_zone.setOutlineColor(sf::Color::Blue);

    this->Net_zone.setSize(sf::Vector2f(WIDTH-20, (HEIGHT - 80) / 6));
    this->Net_zone.setFillColor(sf::Color::White);
    this->Net_zone.setOutlineThickness(10);
    this->Net_zone.setOutlineColor(sf::Color::Blue);
}

SFML_c::~SFML_c()
{
    delete [] this->cpu_cores;
}

void SFML_c::setText(sf::Text &text, std::string str, sf::Color color, int char_size)
{
    text.setFont(this->_font);
    text.setCharacterSize(char_size);
    text.setString(str.c_str());
    text.setFillColor(color);
}