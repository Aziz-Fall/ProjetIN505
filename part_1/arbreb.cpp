#include "arbreb.h"

using namespace std;

//***************************************
//************ Constructor **************
//***************************************

ArbreB::ArbreB():_racine(nullptr){}

ArbreB::ArbreB(const Sommet & sommet): _racine(nullptr)
{
    _racine = new Sommet(sommet.getSommet());
}

//***************************************
//************ Destructor ***************
//***************************************

ArbreB::~ArbreB(){ supprimerSommets(_racine);}

/**
 * @brief This method adds each connected pair
 * of nodes to the output stream.
 * 
 * @param s: binary tree root
 * @param fstream: output stream
 */
void ArbreB::ecritSommet(Sommet *s, ofstream & fstream)
{
    if( !s ) return;
    if( s->getFilsGauche())
        fstream << "\t \"" + s->toString() + "\" -> \"" + s->getFilsGauche()->toString() + "\"\n";
    ecritSommet(s->getFilsGauche(), fstream);
    if( s->getFilsDroite())
        fstream << "\t \"" + s->toString() + "\" -> \"" + s->getFilsDroite()->toString() + "\"\n";
    ecritSommet(s->getFilsDroite(), fstream);
}

/**
 * @brief This method creates a tree.dot file 
 * that will be used to generate an image
 * of the binary tree, using graphviz.
 */
void ArbreB::genereArbreB()
{
    ofstream fstream("tree.dot", ofstream::trunc | ofstream::in);

    fstream << "digraph binaryTree{\n";
    fstream << "\tnode [fontname=\"Arial\"];\n";
    ecritSommet(_racine, fstream);
    fstream << "}";
    fstream.close();
}

/**
 * @brief This method adds a new root the binary tree.
 * 
 * @param s: a pair that contains a character and its number of occurence.
 */
void ArbreB::operator<(const pair<char, int> & s)
{
    if( !this->_racine )
    {
        this->_racine = new Sommet(s);
    }
    else
    {
        int newNbOc(this->_racine->getSommet().second + s.second);
        Sommet *newRacine = new Sommet(make_pair(s.first, newNbOc));
        newRacine->setFilsGauche( new Sommet(s));
        newRacine->setFilsDroite(_racine);

        this->_racine = newRacine;
    }
}

/**
 * This method put each leaf of s in the vector sommets
 * @param s: binary tree root
 * @param sommets: a list of nodes.
 */
void decompose(Sommet *s, vector<pair<char, int>> & sommets)
{
    if( s && !s->getFilsGauche() && !s->getFilsDroite() )
    {
        sommets.push_back(s->getSommet());
        return;
    }

    decompose(s->getFilsGauche(), sommets);
    decompose(s->getFilsDroite(), sommets);
}

/**
 * @brief DecomposeArbre is a method that take all the leafs of 
 * the binary tree and put them in a vector.
 * 
 * @return std::vector<pair<char, int>>: a list of nodes.
 */
std::vector<pair<char, int>> ArbreB::decomposeArbre()
{
    vector<pair<char, int>> sommets;

    decompose(_racine, sommets);

    return sommets;
}

/**
 * @brief Merge two binary trees and return the result.
 * 
 * @param a1 left binary tree
 * @param a2 right binary tree
 * @return ArbreB*: new tree that has a1 as a1 lift child
 *                  and a2 as a right child.
 */
ArbreB *operator+(ArbreB & a1, ArbreB & a2)
{
    int newNbOc(a1._racine->getSommet().second + a2._racine->getSommet().second);
    Sommet *newRacine = new Sommet(make_pair(-1, newNbOc));
    newRacine->setFilsGauche(a1._racine);
    newRacine->setFilsDroite(a2._racine);
    ArbreB *newArbre = new ArbreB;
    newArbre->_racine = newRacine;
    a1._racine = a2._racine = NULL;
    delete &a1;
    delete &a2;
    return newArbre;
}


void update(Sommet *racine, Sommet sommet, std::pair<char, int> & s)
{
    if( !racine ) return;

    if( racine->getSommet() == sommet.getSommet() )
    {
        //check if the node is a leaf.
        if( racine && !racine->getFilsGauche() && !racine->getFilsDroite() )
        {
            racine->setSommet(s);
            return;
        }
    }
    else
    {
        update(racine->getFilsGauche(), sommet, s);
        update(racine->getFilsDroite(), sommet, s);
    }
    
}

bool rechercheSommet(Sommet *racine, const Sommet & sommet)
{
    if( !racine ) return false; 
    
    if( racine->getSommet() == sommet.getSommet() ) return true;
     
    return rechercheSommet(racine->getFilsGauche(), sommet) || rechercheSommet(racine->getFilsDroite(), sommet);
}

/**
 * Update node
 * @param sommet
 * @param s
 */
void ArbreB::updateSommet(const Sommet & sommet, std::pair<char, int> & s)
{
    update(this->_racine, sommet, s);
}

/**
 * This method returns True if the node sommet  
 * was found in the binary tree, otherwise it returns false
 * @param sommet
 * @return boolean
 */
bool ArbreB::recherche(const Sommet & sommet)
{
    return rechercheSommet(this->_racine, sommet);
}
