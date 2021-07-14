/*
** EPITECH PROJECT, 2021
** Toy
** File description:
** Exercise 01
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include <iostream>

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY,
        };
        Toy(ToyType type, std::string const &name, std::string const &filename);
        Toy(Toy const &copy);
        Toy();
        virtual ~Toy();
        int getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string const &name);
        bool setAscii(std::string const &filename);
        Picture _picture;
        virtual void speak(std::string const &statement);
        virtual bool speak_es(std::string const &statement);
        Toy &operator=(Toy const &toy);
        Toy &operator<<(std::string const &flux);
        class Error {
            public :
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK,
                };
                Error();
                std::string what() const;
                std::string where() const;
                ErrorType type;
                void setType(ErrorType type);
        };
        Error const &getLastError() const;
    protected:
        ToyType _type;
        std::string _name;
        Error error;
    private:
};

std::ostream &operator<<(std::ostream &flux, Toy const &toy);

#endif /* !TOY_HPP_ */
