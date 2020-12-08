#include "decryptage.h"

using namespace std;

Decryptage::Decryptage(ArbreB *arbreB, string messagesCryptes)
{
    decryptMessage(arbreB->getRacine(), arbreB->getRacine(), messagesCryptes, 0);
}
/**
 * @brief decrypte a message encrypted.
 * 
 * @param root
 * @param current 
 * @param donneesCryptees 
 * @param position 
 */
void Decryptage::decryptMessage(Sommet *root, Sommet *current, std::string donneesCryptees, size_t position)
{
    if( position > donneesCryptees.length())
        return;

    int bin = donneesCryptees[position] - 48;

    if(current && !current->getFilsGauche() && !current->getFilsDroite())
    {
        _messagesDechiffres += string(1, current->getSommet().first);
        decryptMessage(root, root, donneesCryptees, position);
    }
    else if( bin == 1 )
    {
        decryptMessage(root, current->getFilsDroite(), donneesCryptees, position + 1);
    }
    else if( bin == 0 )
    {
        decryptMessage(root, current->getFilsGauche(), donneesCryptees, position + 1);
    }
}

/**
 * @brief Get the Message Dechiffres object
 * 
 * @return string 
 */
string Decryptage::getMessageDechiffres()
{
    return _messagesDechiffres;
}

