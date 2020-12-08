#pragma once

#include "sommet.h"
#include <iostream>
#include <fstream>
#include <vector>

/**
 * Class ArbreB defines a binary tree
 * composed by a root node (racine).
 * @author: ...(charaf-eddine & aziz fall)...
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
        ~ArbreB();
        void operator<(const std::pair<char, int> & s);
        friend ArbreB *operator+(ArbreB & a1, ArbreB & a2);
        Sommet *getRacine();
        void setRacine(Sommet *s);
        bool recherche(const Sommet & sommet);
        std::vector<std::pair<char, int>> decomposeArbre();
        void updateSommet(const Sommet & sommet, std::pair<char, int> & s);
        void genereArbreB();
};

