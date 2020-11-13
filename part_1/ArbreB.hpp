#pragma once

#include "Sommet.hpp"
#include <iostream>
#include <fstream>
#include <vector>

class ArbreB
{
    private:
        Sommet _root;
        ArbreB *_left;
        ArbreB *_right;

        friend void ecritSommet(ArbreB *a, std::ofstream & fstream);
        void deleteArbreB(ArbreB *arbreB);
    public:
        ArbreB();
        ArbreB(const Sommet & sommet);
        ArbreB( int letter, int nbOc);
        ArbreB( const ArbreB & arbreB);
        ~ArbreB();
        ArbreB *fusionne(ArbreB & t1, ArbreB & t2);
        //ArbreB & operator=(const ArbreB & arbreB);
        void operator<(const Sommet & sommet);
        Sommet & operator>(const Sommet & sommet);
        Sommet recherche(const Sommet & sommet);
        void updateNbOc(const Sommet & sommet, int newNbOc);
        std::vector<Sommet> & decompose();
        void genereArbreB();
};
