#pragma once

#include <iterator>
#include <fstream>
#include <QString>
#include <string>
#include <map>
#include <queue>

#include "sommet.h"
#include "arbreb.h"

class CompareArbre
{
    public:
        bool operator()(ArbreB *a1, ArbreB *a2)
        {
            if( a1->getRacine()->getSommet().second == a2->getRacine()->getSommet().second )
                return a1->getRacine()->getSommet().first > a2->getRacine()->getSommet().first;

            return ( a1->getRacine()->getSommet().second > a2->getRacine()->getSommet().second);
        }
};

/**
 * @brief Crypt a file using Huffman algoritm.
 */
class Cryptage
{
    private:
        std::string _nomFichier; 
        QString _donneesCryptees;
        QString _textes;
        std::map<char, int> _mapOc;
        std::map<char, std::vector<int>> _charCryptee;
        std::priority_queue<ArbreB *, std::vector<ArbreB*>, CompareArbre> _pq;
        ArbreB *_arbreB;
        void _initMap();
        void _construitArbreB();
        void _cryptDonnees();
        void cryptChar(Sommet *racine, const Sommet & s);
    public:
        Cryptage();
        Cryptage(std::string textACrypte, int size);
        Cryptage(std::string nomFichier);
        ~Cryptage();
        void setNameFile(std::string nomFichier);
        QString getDonneesCryptees();
        QString getTextes();
        void setTextes(QString textes);
        ArbreB *getArbreB();
};
