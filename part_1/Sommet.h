#pragma once 

#include <iostream>
#include <utility>

/**
 * Class Sommet define a tree top 
 * composited by a pair that contain
 * a char(_lettre) and his number 
 * of occurrence (_nbOc) and the 
 * son left et right.
 * @author: ...(achraf & aziz fall)...
 * @version: 1.0.0
*/
class Sommet
{
    private:
        std::pair<char, int> _s;
        Sommet *_gauche;
        Sommet *_droite;

        
    public:
        Sommet();
        Sommet(std::pair<char, int> s);
        ~Sommet();
        void setSommet(std::pair<char, int> & s);
        std::pair<char, int> getSommet() const;
        Sommet *getFilsGauche();
        Sommet *getFilsDroite();
        void setFilsGauche(Sommet *g);
        void setFilsDroite(Sommet *d);
        void printSommet(Sommet *s);
        friend std::ostream & operator<<(std::ostream & os, const Sommet & t);
        std::string  toString();

};

void supprimerSommets(Sommet *s);