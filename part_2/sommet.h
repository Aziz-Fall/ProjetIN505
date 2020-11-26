#pragma once

#include <iostream>
#include <utility>

/**
 * Class Sommet represents a tree data structure 
 * composed of left and right children and a pair 
 * that contains a char(_lettre) and its number
 * of occurences(_nbOc)
 * @author: ...(charaf-eddine & aziz fall)...
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
        bool recherche(Sommet *root, const Sommet & s);
        void printSommet(Sommet *s);
        friend std::ostream & operator<<(std::ostream & os, const Sommet & t);
        std::string  toString();

};

void supprimerSommets(Sommet *s);
