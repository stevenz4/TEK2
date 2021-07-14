/*
** EPITECH PROJECT, 2021
** Cesar
** File description:
** Exercise 02
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();
    protected:
    private:
};

#endif /* !CESAR_HPP_ */
