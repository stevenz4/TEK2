/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Wrap.hpp"
class Box : public Wrap {
    public:
        Box(std::string);
        ~Box();
        Object *getToy() {return (toy);};
        void setToy(Object *_toy) {toy = _toy;};
        virtual bool wrapMeThat(Object *obj);
    protected:
        Object *toy;
    private:
};

#endif /* !BOX_HPP_ */
