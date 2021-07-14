/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"
class Wrap : public Object{
    public:
        Wrap(std::string);
        virtual ~Wrap();
        bool getIsOpen() {return (isOpen);};
        Object *getObj() {return (obj);};
        void CloseMe() {isOpen = false;};
        void OpenMe() {isOpen = true;};
        void setObj(Object *_obj) {obj = _obj;};
    protected:
        bool isOpen;
        Object *obj;
    private:
       
};

Object *MyUnitTests(Object **obj);

#endif /* !WRAP_HPP_ */
