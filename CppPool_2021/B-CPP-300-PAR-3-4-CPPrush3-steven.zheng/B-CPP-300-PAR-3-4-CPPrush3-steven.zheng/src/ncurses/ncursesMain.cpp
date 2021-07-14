/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ncursesMain
*/

#include "ncurses.hpp"

void DisplayNcurses(Core core)
{
    initscr();
    noecho();
    cbreak();
    timeout(400);
    curs_set(0);
    while (1) {
        clear();
        getmaxyx(stdscr, core.row, core.column);
        core._time.refreshTime();
        Display(core);
        napms(200);
        refresh();
    }
    curs_set(1);
    nocbreak();
    endwin();

}

void Display(Core core)
{
    WINDOW *Cwindow;

    Cwindow = subwin(stdscr, 40, 100, 1 + (core.row/2 - 20), 2 + (core.column/2 - 50));
    box(Cwindow, 0, 0);
    mvwprintw(Cwindow, 1, 3, core._time.getTime().c_str());
    mvwprintw(Cwindow, 1, 96 - core._hostname_username.getHostname().length(), core._hostname_username.getHostname().c_str());
    mvwprintw(Cwindow, 2, 96 - core._hostname_username.getUsername().length(), core._hostname_username.getUsername().c_str());
    mvwprintw(Cwindow, 38, 50 - (16 + core._sysName_kernelVer.getKernelVersion().length())/ 2, ("Kernel Version: " + core._sysName_kernelVer.getKernelVersion()).c_str());
    mvwprintw(Cwindow, 37, 50 - (9 + core._sysName_kernelVer.getOsName().length())/ 2, ("OS Name: " + core._sysName_kernelVer.getOsName()).c_str());

    DisplayCPU(core);
    DisplayRAM(core);
    DisplayNetwork(core);
}

void DisplayCPU(Core core)
{
    WINDOW *Cwindow;
    std::string str = "Activity: " + std::to_string(core._cores.getActivity()).substr(0, 4) + "%%";
    std::string str2 = ("Freq: " + std::to_string(core._cores.getTotalFrequency())) + " MHz";

    Cwindow = subwin(stdscr, 9, 80, 0 + (core.row/2 - 15), 7 + (core.column/2 - 45));
    mvwprintw(Cwindow, 1, 40 - ("CPU: " + core._cores.getModel()).length() / 2, ("CPU: " + core._cores.getModel()).c_str());
    mvwprintw(Cwindow, 2, 40 - str2.length() / 2, str2.c_str());
    mvwprintw(Cwindow, 3, 40 - str2.length() / 2, str.c_str());
    for (int i = 0; i != 80; i++)
        mvwprintw(Cwindow, 4, i, "_");
    for (int i = 0, y = 5, x = 1; i != core._cores.GetNumberCores(); i++, x += 13) {
        mvwprintw(Cwindow, y, x, ("cpu" + std::to_string(i) + ":" + std::to_string(core._cores.getCoreActivity()[i]).substr(0,4) + "%%").c_str());
        if (x >= 65) {
            y++;
            x = -12;
        }
    }
    box(Cwindow, 0, 0);
}

void DisplayRAM(Core core)
{
    WINDOW *Cwindow;

    Cwindow = subwin(stdscr, 9, 80, 10 + (core.row/2 - 15), 7 + (core.column/2 - 45));
    mvwprintw(Cwindow, 1, 38, "RAM");
    mvwprintw(Cwindow, 3, 20, ("Total: " + std::to_string(core._ram.getRamTotal()).substr(0,4) + " Gb").c_str());
    mvwprintw(Cwindow, 5, 20, ("Free: " + std::to_string(core._ram.getRamFree()).substr(0,4) + " Gb").c_str());
    mvwprintw(Cwindow, 3, 45, ("Used: " + std::to_string(core._ram.getRamUsed()).substr(0,4) + " Gb").c_str());
    mvwprintw(Cwindow, 5, 45, ("Used Percent: " + std::to_string(core._ram.Usedpercent()).substr(0,4) + "%%").c_str());
    
    box(Cwindow, 0, 0);

}

void DisplayNetwork(Core core)
{
    core._network.refreshNetInterface();
    WINDOW *Cwindow;

    Cwindow = subwin(stdscr, 9, 80, 20 + (core.row/2 - 15), 7 + (core.column/2 - 45));
    mvwprintw(Cwindow, 1, 36, "Network");
    mvwprintw(Cwindow, 2, 1, "Interface");
    mvwprintw(Cwindow, 2, 15, "receive bytes");
    mvwprintw(Cwindow, 2, 30, "receive packets");
    mvwprintw(Cwindow, 2, 45, "transmit bytes");
    mvwprintw(Cwindow, 2, 60, "transmit packets");
    for (int i = 0; i < core._network.getInterfaceNb(); i++) {
        mvwprintw(Cwindow, 3 + i, 1, core._network.netInter[i]._interface.c_str());
        mvwprintw(Cwindow, 3 + i, 15, std::to_string(core._network.netInter[i].receive[0]).c_str());
        mvwprintw(Cwindow, 3 + i, 30, std::to_string(core._network.netInter[i].receive[1]).c_str());
        mvwprintw(Cwindow, 3 + i, 45, std::to_string(core._network.netInter[i].transmit[0]).c_str());
        mvwprintw(Cwindow, 3 + i, 60, std::to_string(core._network.netInter[i].transmit[1]).c_str());
    }
    
    
    box(Cwindow, 0, 0);

}