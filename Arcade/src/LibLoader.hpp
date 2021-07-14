/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include <dlfcn.h>

class LibLoader {
    public:
        LibLoader(char const *path, char const *function);
        ~LibLoader();
        void *get_lib();
        void *get_ptr();
    private:
        void *libhandle;
        void *ptr;
    protected:
};

#endif /* !LIBLOADER_HPP_ */
