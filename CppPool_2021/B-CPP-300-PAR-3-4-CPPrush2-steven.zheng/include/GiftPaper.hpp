/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"
class GiftPaper : public Wrap {
    public:
        GiftPaper(std::string);
        ~GiftPaper();
        Object *getBox() {return (box);};
        void setBox(Object *_box) {box = _box;};
        virtual bool wrapMeThat(Object *obj);
    protected:
        Object *box;
    private:
};

#endif /* !GIFTPAPER_HPP_ */
