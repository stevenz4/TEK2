/*
** EPITECH PROJECT, 2021
** Little Pony and Teddy
** File description:
** Rush2
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <string>

class Object {
    public:
        Object(std::string title);
        ~Object();
        std::string getTitle();
        bool getIsTaken();
        std::string getType() {return (type);};
        virtual bool wrapMeThat(Object *obj) {obj=obj; return (true);};
        virtual void OpenMe() {};
        virtual void CloseMe() {};
    protected:
        std::string _title;
        bool _isTaken;
        std::string type;
    private:
};

std::ostream &operator<<(std::ostream &flux, Object &object);
Object **MyUnitTests();

#endif /* !OBJECT_HPP_ */
