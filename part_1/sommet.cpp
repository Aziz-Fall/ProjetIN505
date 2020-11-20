#include "sommet.h"

using namespace std;

//***************************************
//************ Constructor **************
//***************************************

Sommet::Sommet():_s(make_pair(-1, 0)), _gauche(nullptr), _droite(nullptr){}

Sommet::Sommet(pair<char, int> s): _s(s), _gauche(nullptr), _droite(nullptr){}

//***************************************
//************ Destructor ***************
//***************************************

Sommet::~Sommet(){}

//***************************************
//************ Setters ******************
//***************************************

void Sommet::setSommet(pair<char, int> & s)
{
    if( _s != s)
    {
        _s.first = s.first;
        _s.second = s.second;
    }
}
void Sommet::setFilsGauche(Sommet *g) {if( g ) _gauche = g;}
void Sommet::setFilsDroite(Sommet *d) { if( d ) _droite = d;}

//***************************************
//************ Getter *******************
//***************************************

pair<char, int> Sommet::getSommet() const { return _s;}
Sommet *Sommet::getFilsGauche(){ return _gauche;}
Sommet *Sommet::getFilsDroite(){return _droite;}

/**
 * @brief Return a description of the classe
 * 
 */
string Sommet::toString()
{
    if( _s.first == -1 )
        return to_string(_s.second);
    string node(1, _s.first);
    node.append("." + to_string(_s.second));
    return node;
}

/**
 * @brief This method deletes the node s 
 * and all of its children recursively.
 * @param s: binary tree root.
 */
void supprimerSommets(Sommet *s)
{
    if( s )
    {
        supprimerSommets(s->getFilsGauche());
        supprimerSommets(s->getFilsDroite());
    }

    delete s;
    s = nullptr;
    return;
}

/**
 * @brief This method display all nodes (s) recursively.
 * @param s is the root.
 */
void Sommet::printSommet(Sommet *s)
{
    if( !s ) return;

    cout << s->toString() << endl;
    printSommet(s->_gauche);
    printSommet(s->_droite);

}

/**
 * @brief Prints the node to the output stream.
 * @param os: output stream
 * @param s: binary tree root
 * @return output stream.
 */
std::ostream & operator<<(std::ostream & os, const Sommet & s)
{
    return os << s._s.first<< " -> " << s._s.second;
}
