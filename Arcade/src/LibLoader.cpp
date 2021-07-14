/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** LibLoader
*/

#include "LibLoader.hpp"
#include <stdio.h>

LibLoader::LibLoader(char const* path, char const* function)
{
    libhandle = dlopen(path, RTLD_LAZY);
    if (!libhandle)
        perror("dlopen");
    ptr = dlsym(libhandle, function);
    if (!ptr)
        fprintf(stderr, "dlopen: %s", dlerror());
}

LibLoader::~LibLoader()
{
    dlclose(libhandle);
}

void *LibLoader::get_ptr()
{
    return (ptr);
}

void *LibLoader::get_lib()
{
    return (libhandle);
}
