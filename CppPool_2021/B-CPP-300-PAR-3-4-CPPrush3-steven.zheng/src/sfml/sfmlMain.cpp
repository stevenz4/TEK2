/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sfmlMain
*/

#include "sfml.hpp"

void DisplaySFML(Core core)
{
    SFML_c gk(core);
    float cpu_fre[10];
    float ram_use[10];

    gk._window.create(gk._mode, "MyGKrellM", sf::Style::Default);
    for (int j = 0; j < 10; j++)
        cpu_fre[j] = 0;
    while (gk._window.isOpen()) {
        set_all(&gk);
        event_all(&gk);
        draw_all(&gk);
        for (int j = 0; j != 10; j++) {
            cpu_fre[j] = cpu_fre[j + 1];
        }
        cpu_fre[9] = (core._cores.getTotalFrequency());
        for (int j = 0; j != 10; j++) {
            cpu_fre[j] = cpu_fre[j + 1];
        }
        cpu_fre[9] = (core._cores.getTotalFrequency());
        ram_use[9] = (core._ram.Usedpercent());
        for (int j = 0; j != 10; j++) {
            ram_use[j] = ram_use[j + 1];
        }
        ram_use[9] = (core._ram.Usedpercent());
        set_cpu_graph(&gk, cpu_fre);
        set_ram_graph(&gk, ram_use);
        usleep(500000);
    }
    return;
}

void set_ram_graph(SFML_c *gk, float ram_use[10])
{
    gk->ram_graph.setPoint(0, sf::Vector2f(1440, 400.00));
    gk->ram_graph.setPoint(1, sf::Vector2f(1440, ram_use[0] + 350.00));
    gk->ram_graph.setPoint(2, sf::Vector2f(1480, ram_use[1] + 350.00));
    gk->ram_graph.setPoint(3, sf::Vector2f(1520, ram_use[2] + 350.00));
    gk->ram_graph.setPoint(4, sf::Vector2f(1560, ram_use[3] + 350.00));
    gk->ram_graph.setPoint(5, sf::Vector2f(1600, ram_use[4] + 350.00));
    gk->ram_graph.setPoint(6, sf::Vector2f(1640, ram_use[5] + 350.00));
    gk->ram_graph.setPoint(7, sf::Vector2f(1680, ram_use[6] + 350.00));
    gk->ram_graph.setPoint(8, sf::Vector2f(1720, ram_use[7] + 350.00));
    gk->ram_graph.setPoint(9, sf::Vector2f(1760, ram_use[8] + 350.00));
    gk->ram_graph.setPoint(10, sf::Vector2f(1820, ram_use[9] + 350.00));
    gk->ram_graph.setPoint(11, sf::Vector2f(1820, 400.00));
    gk->ram_graph.setOutlineThickness(1);
    gk->ram_graph.setOutlineColor(sf::Color::Black);
}

void set_all(SFML_c *gk)
{
    gk->hostname.setPosition(WIDTH - 200, 0);
    gk->username.setPosition(WIDTH - 200, HEIGHT/30);
    gk->osName.setPosition(WIDTH/2 - 50, 0);
    gk->Net_zone.setPosition(10, 480);
    gk->kernelVersion.setPosition(WIDTH/2 - 200, HEIGHT/30);
    gk->cpu_name.setPosition(10, 80);
    gk->cpu_frequency.setPosition(10, 140);
    gk->cpu_frequency_2.setPosition(1500, 220);
    gk->cpu_activity.setPosition(10, 200);
    gk->CPU_zone.setPosition(10,80);
    gk->RAM_zone.setPosition(10, 280);
    gk->Net_zone.setPosition(10, 480);
    gk->ram_total.setPosition(10, 280);
    gk->ram_free.setPosition(10, 300);
    gk->ram_used.setPosition(10, 320);
    gk->ram_used_percent.setPosition(10, 340);
    gk->ram_used_2.setPosition(1500, 400);
    gk->ram_section.setPosition(WIDTH/2, 280);
    gk->_core._time.refreshTime();
    gk->setText(gk->date, gk->_core._time.getTime().c_str(), sf::Color::White, 20);
    gk->setText(gk->hostname, gk->_core._hostname_username.getHostname(), sf::Color::White, 20);
    gk->setText(gk->username, gk->_core._hostname_username.getUsername(), sf::Color::White, 20);
    gk->setText(gk->osName, "OS Name: " + gk->_core._sysName_kernelVer.getOsName(), sf::Color::White, 20);
    gk->setText(gk->kernelVersion, "Kernel Version: " + gk->_core._sysName_kernelVer.getKernelVersion(), sf::Color::White, 20);
    gk->setText(gk->cpu_name, "CPU: " + gk->_core._cores.getModel(), sf::Color::Black, 15);
    gk->setText(gk->cpu_frequency, ("Freq: " + std::to_string(gk->_core._cores.getTotalFrequency())) + " MHz", sf::Color::Black, 15);
    gk->setText(gk->cpu_frequency_2, ("CPU's Frequency: " + std::to_string(gk->_core._cores.getTotalFrequency())) + " MHz", sf::Color::Black, 13);
    gk->setText(gk->cpu_activity, "Activity: " + std::to_string(gk->_core._cores.getActivity()).substr(0, 4) + "%", sf::Color::Black, 15);
    gk->setText(gk->ram_total, "Total: " + std::to_string(gk->_core._ram.getRamTotal()).substr(0,4) + " Gb", sf::Color::Black, 20);
    gk->setText(gk->ram_free, "Free: " + std::to_string(gk->_core._ram.getRamFree()).substr(0,4) + " Gb", sf::Color::Black, 20);
    gk->setText(gk->ram_used, "Used: " + std::to_string(gk->_core._ram.getRamUsed()).substr(0,4) + " Gb", sf::Color::Black, 20);
    gk->setText(gk->ram_used_percent, "Used Percent: " + std::to_string(gk->_core._ram.Usedpercent()).substr(0,4) + "%", sf::Color::Black, 20);
    gk->setText(gk->ram_used_2, "Used Percent: " + std::to_string(gk->_core._ram.Usedpercent()).substr(0,4) + "%", sf::Color::Black, 13);
    gk->setText(gk->ram_section, "RAM", sf::Color::Black, 15);
    for (int j = 0, gap_x = 0, gap_y = 40; j < gk->_core._cores.GetNumberCores(); j++) {
        gk->setText(gk->cpu_cores[j], "cpu" + std::to_string(j) + ": " + std::to_string(gk->_core._cores.getCoreActivity()[j]).substr(0,4) + "%", sf::Color::Black, 15);
        gk->cpu_cores[j].setPosition(500 + gap_x, 80 + gap_y);
        gap_y += 40;
        if (gap_y == 160) {
            gap_x += 100;
            gap_y = 40;
        } 
    }
    for (int j = 0, gap_x = 0; j < gk->_core._cores.GetNumberCores() / 3 + 1; j++) {
        gk->cpu_core_separator[j].setPosition(490 + gap_x, 80);
        gap_x += 100;
    }
    gk->_core._network.refreshNetInterface();

    gk->txtInterface = new sf::Text[gk->_core._network.getInterfaceNb()+ 1];
    gk->txtReceive_bytes = new sf::Text[gk->_core._network.getInterfaceNb()+ 1];
    gk->txtReceive_packets = new sf::Text[gk->_core._network.getInterfaceNb()+ 1];
    gk->txtTransmit_bytes = new sf::Text[gk->_core._network.getInterfaceNb()+ 1];
    gk->txtTransmit_packets = new sf::Text[gk->_core._network.getInterfaceNb() + 1];

    gk->txtNetwork.setPosition(WIDTH/2, 490);
    gk->setText(gk->txtNetwork, "Network", sf::Color::Black, 20);
    gk->setText(gk->txtInterface[0], "Interface", sf::Color::Black, 20);
    gk->setText(gk->txtReceive_bytes[0], "Receive bytes", sf::Color::Black, 20);
    gk->setText(gk->txtReceive_packets[0], "receive packets", sf::Color::Black, 20);
    gk->setText(gk->txtTransmit_bytes[0], "transmit bytes", sf::Color::Black, 20);
    gk->setText(gk->txtTransmit_packets[0], "transmit packets", sf::Color::Black, 20);
    for (int i = 0; i < gk->_core._network.getInterfaceNb(); i++) {
        gk->setText(gk->txtInterface[i + 1], gk->_core._network.netInter[i]._interface, sf::Color::Black, 20);
        gk->setText(gk->txtReceive_bytes[i + 1], std::to_string(gk->_core._network.netInter[i].receive[0]), sf::Color::Black, 20);
        gk->setText(gk->txtReceive_packets[i + 1], std::to_string(gk->_core._network.netInter[i].receive[1]), sf::Color::Black, 20);
        gk->setText(gk->txtTransmit_bytes[i + 1], std::to_string(gk->_core._network.netInter[i].transmit[0]), sf::Color::Black, 20);
        gk->setText(gk->txtTransmit_packets[i + 1], std::to_string(gk->_core._network.netInter[i].transmit[1]), sf::Color::Black, 20);
    }
    for (int i = 0; i < gk->_core._network.getInterfaceNb(); i++) {
        gk->txtInterface[i].setPosition(10 + i * 200, 500);
        gk->txtReceive_bytes[i].setPosition(10 + i * 200, 520);
        gk->txtReceive_packets[i].setPosition(10 + i * 200, 540);
        gk->txtTransmit_bytes[i].setPosition(10 + i * 200, 560);
        gk->txtTransmit_packets[i].setPosition(10 + i * 200, 580);
    }
}

void set_cpu_graph(SFML_c *gk, float cpu_fre[10])
{
    gk->cpu_graph.setPoint(0, sf::Vector2f(1440, 220));
    gk->cpu_graph.setPoint(1, sf::Vector2f(1440,cpu_fre[0] / 50 + 100));
    gk->cpu_graph.setPoint(2, sf::Vector2f(1480,cpu_fre[1] / 50 + 100));
    gk->cpu_graph.setPoint(3, sf::Vector2f(1520,cpu_fre[2] / 50 + 100));
    gk->cpu_graph.setPoint(4, sf::Vector2f(1560,cpu_fre[3] / 50 + 100));
    gk->cpu_graph.setPoint(5, sf::Vector2f(1600,cpu_fre[4] / 50 + 100));
    gk->cpu_graph.setPoint(6, sf::Vector2f(1640,cpu_fre[5] / 50 + 100));
    gk->cpu_graph.setPoint(7, sf::Vector2f(1680,cpu_fre[6] / 50 + 100));
    gk->cpu_graph.setPoint(8, sf::Vector2f(1720,cpu_fre[7] / 50 + 100));
    gk->cpu_graph.setPoint(9, sf::Vector2f(1760,cpu_fre[8] / 50 + 100));
    gk->cpu_graph.setPoint(10, sf::Vector2f(1820,cpu_fre[9] / 50 + 100));
    gk->cpu_graph.setPoint(11, sf::Vector2f(1820, 220));
    gk->cpu_graph.setOutlineThickness(1);
    gk->cpu_graph.setOutlineColor(sf::Color::Black);

}

void event_all(SFML_c *gk)
{
    while (gk->_window.pollEvent(gk->_event)) {
        if (gk->_event.type == sf::Event::Closed)
            gk->_window.close();
    }
}

void draw_all(SFML_c *gk)
{
    gk->_window.draw(gk->wallpaper.sprite);
    gk->_window.draw(gk->date);
    gk->_window.draw(gk->username);
    gk->_window.draw(gk->hostname);
    gk->_window.draw(gk->osName);
    gk->_window.draw(gk->kernelVersion);
    gk->_window.draw(gk->CPU_zone);
    gk->_window.draw(gk->cpu_name);
    gk->_window.draw(gk->cpu_frequency);
    gk->_window.draw(gk->cpu_activity);
    gk->_window.draw(gk->cpu_graph);
    gk->_window.draw(gk->cpu_frequency_2);
    gk->_window.draw(gk->RAM_zone);
    gk->_window.draw(gk->Net_zone);
    gk->_window.draw(gk->ram_total);
    gk->_window.draw(gk->ram_free);
    gk->_window.draw(gk->ram_used);
    gk->_window.draw(gk->ram_used_percent);
    gk->_window.draw(gk->ram_graph);
    gk->_window.draw(gk->ram_used_2);
    gk->_window.draw(gk->txtNetwork);
    gk->_window.draw(gk->ram_section);
    for (int i = 0; i < gk->_core._network.getInterfaceNb(); i++) {
        gk->_window.draw(gk->txtInterface[i]);
        gk->_window.draw(gk->txtReceive_bytes[i]);
        gk->_window.draw(gk->txtReceive_packets[i]);
        gk->_window.draw(gk->txtTransmit_bytes[i]);
        gk->_window.draw(gk->txtTransmit_packets[i]);
    }
    for (int j = 0; j < gk->_core._cores.GetNumberCores(); j++)
        gk->_window.draw(gk->cpu_cores[j]);
    for (int j = 0; j < gk->_core._cores.GetNumberCores() / 3 + 1; j++)
        gk->_window.draw(gk->cpu_core_separator[j]);
    gk->_window.display();
}