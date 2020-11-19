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
 * This method put the link between the root and her son
 * for each node of binary tree in the flux
 * @param s: a tree top
 * @param fstream: output flux
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
 * This method put the binary tree discription in a file
 * that allow the rule of digraphz.
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
 * This method add a tree top in the binary tree.
 * @param s: a pair contained a letter and his number of occurrence.
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
 * @param s: a tree top
 * @param sommets: vector contained a pair of values.
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
 * decomposeArbre is a method that take all leaf of
 * the binary tree and put them in a vector.
 */
std::vector<pair<char, int>> ArbreB::decomposeArbre()
{
    vector<pair<char, int>> sommets;

    decompose(_racine, sommets);

    return sommets;
}

/**
 * Merge two binary tree and return the result.
 * @param a1: binary tree
 * @param a2: binary tree
 * @return new tree that's the merging of a1 and a2
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
 * Update a top tree passing in argument by 
 * the pair s.
 * @param sommet
 * @param s
 */
void ArbreB::updateSommet(const Sommet & sommet, std::pair<char, int> & s)
{
    update(this->_racine, sommet, s);
}

/**
 * Search a tree top in the binary tree and return 
 * True if tree top finded else false.
 * @param sommet
 * @return boolean
 */
bool ArbreB::recherche(const Sommet & sommet)
{
    return rechercheSommet(this->_racine, sommet);
}
