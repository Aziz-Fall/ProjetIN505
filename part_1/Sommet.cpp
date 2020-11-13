#include "Sommet.hpp"

using namespace std;

Sommet::Sommet():_lettre(-1), _nbOc(0){}

Sommet::Sommet(char lettre, int nbOc): _lettre(lettre), _nbOc(nbOc){}
Sommet::~Sommet(){}

void Sommet::setLettre(int lettre){ _lettre = lettre; }
char Sommet::getLettre() const { return _lettre;}
void Sommet::setNbOc(int nbOc) { _nbOc = nbOc; }
int Sommet::getNbOc() const { return _nbOc; }

std::ostream & operator<<(std::ostream & os, const Sommet & s)
{
    return os << s._lettre << " -> " << s._nbOc;
}

string Sommet::toString()
{
    if( _lettre == -1 )
        return to_string(_nbOc); 
    string node(1, _lettre);
    return node + " (" + to_string(_nbOc) + ")";
}