#pragma once 

#include <iostream>

/*
 * Class Sommet define a tree top 
 * composited by a char(_lettre) and his number of occurrence (_nbOc).
*/
class Sommet
{
    private:
        char _lettre;
        int _nbOc; 
    public:
        Sommet();
        Sommet(char lettre, int nbOc);
        ~Sommet();
        void setLettre(int lettre);
        char getLettre()const;
        void setNbOc(int nbOc);
        int getNbOc() const;
        friend std::ostream & operator<<(std::ostream & os, const Sommet & t);
        std::string  toString();

};