/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Arcade
*/

//#include <SDL2/SDL.h>
#include "src/SDL2/sdl2.hpp"
#include "src/snake/snake.hpp"
#include "src/Arcade.hpp"
#include "src/LibLoader.hpp"

int create_loop(IGraphics *lib_graphic)
{
    Arcade Menu(lib_graphic);
    
    Menu.menuSetup();
    Menu.menuLoop();
    return 0;
}

int core(char *lib_path)
{
    typedef IGraphics*(*Loader)();
    IGraphics *lib_graphic;
    Loader loader;
    LibLoader lib(lib_path, "create_obj");

    *(void**) (&loader) = lib.get_ptr();
    lib_graphic = loader();
    create_loop(lib_graphic);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "USAGE:\n\t./arcade <library>\n\nDESCRIPTION:\n\t<library> : in /lib folder" << std::endl;
        return 84;
    }
    core(argv[1]);
    return 0;
}