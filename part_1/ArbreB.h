#pragma once

#include "Sommet.h"
#include <iostream>
#include <fstream>
#include <vector>

/**
 * Class ArbreB define a binary tree
 * composited by a Node (racine) that 
 * is the root of the tree. The root
 * is composited the son left et right 
 * and primitives: a letter (char) 
 * and his number of occurence (int).
 * @author: ...(achraf & aziz fall)...
 * @version: 1.0.0
*/
class ArbreB
{
    private:
        Sommet *_racine;
        void ecritSommet(Sommet *s, std::ofstream & fstream);

    public:
        ArbreB();
        ArbreB(const Sommet & sommet);
        ArbreB( const ArbreB & arbreB);
        ~ArbreB();
        ArbreB *fusionne(ArbreB & t1, ArbreB & t2);
        void operator<(const std::pair<char, int> & s);
        friend ArbreB *operator+(ArbreB & a1, ArbreB & a2);
        Sommet recherche(const Sommet & sommet);
        std::vector<std::pair<char, int>> decomposeArbre();
        void updateNbOc(const Sommet & sommet, int newNbOc);
        void printArbre();
        void genereArbreB();
};

