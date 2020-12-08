#pragma once

#include <iostream>
#include "arbreb.h"
#include "sommet.h"     

/**
 * @brief Decrypt a message
 */
class Decryptage
{
    private:
        std::string _messagesDechiffres;
        void decryptMessage(Sommet *root, Sommet *current, std::string donneesCryptees, size_t position);

    public:
        Decryptage(ArbreB *arbreB, std::string messagesCryptes);
        std::string getMessageDechiffres();
};