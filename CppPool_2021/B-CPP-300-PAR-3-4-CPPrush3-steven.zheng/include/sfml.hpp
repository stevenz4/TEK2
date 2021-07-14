/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "Core.hpp"
#include "IMonitorDisplay.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define WIDTH (1920)
#define HEIGHT (1080)

typedef struct sprite_s {
    sf::Texture texture;
    sf::Sprite sprite;
} sprite_t;

class SFML_c : public IMonitorDisplay {
    public :
        SFML_c(Core core);
        ~SFML_c();
        Core _core;
        sf::RenderWindow _window;
        sf::VideoMode _mode;
        sf::Event _event;
        sf::Font _font;
        sf::Text date;
        sf::Text username;
        sf::Text hostname;
        sf::Text osName;
        sf::Text kernelVersion;
        sprite_t wallpaper;

        sf::RectangleShape CPU_zone;
        sf::Text cpu_name;
        sf::Text cpu_frequency;
        sf::Text cpu_frequency_2;
        sf::Text cpu_activity;
        sf::Text *cpu_cores;
        sf::RectangleShape *cpu_core_separator;
        sf::ConvexShape cpu_graph;
        
        sf::RectangleShape RAM_zone;
        sf::Text ram_section;
        sf::Text ram_total;
        sf::Text ram_free;
        sf::Text ram_used;
        sf::Text ram_used_percent;
        sf::Text ram_used_2;
        sf::ConvexShape ram_graph;

        sf::RectangleShape Net_zone;
        sf::Text txtNetwork;
        sf::Text *txtInterface;
        sf::Text *txtReceive_packets;
        sf::Text *txtTransmit_bytes;
        sf::Text *txtReceive_bytes;
        sf::Text *txtTransmit_packets;
        void setText(sf::Text &, std::string, sf::Color, int);
    protected :
    private :
};



void DisplaySFML(Core core);
void draw_all(SFML_c *gk);
void event_all(SFML_c *gk);
void set_cpu_graph(SFML_c *gk, float cpu_fre[5]);
void set_all(SFML_c *gk);
void set_ram_graph(SFML_c *gk, float ram_use[10]);

#endif /* !SFML_HPP_ */
