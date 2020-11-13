#include "ArbreB.hpp"

using namespace std;

ArbreB::ArbreB():_root(Sommet()), _left(nullptr), _right(nullptr){}
ArbreB::ArbreB(const Sommet & sommet):_root(sommet), _left(nullptr), _right(nullptr)
{
    //cout << _root.toString() << endl;
}
ArbreB::ArbreB( int letter, int nbOc):_root(Sommet(letter, nbOc)), _left(nullptr), _right(nullptr){}
ArbreB::ArbreB( const ArbreB & arbreB): _root(arbreB._root)
{
}

ArbreB::~ArbreB(){ deleteArbreB(this);}

/*
 * This method put the link between the root and her son
 * for each node of binary tree (a) in the flux (fstream)
 */
void ecritSommet(ArbreB *a, ofstream & fstream)
{
    if( !a ) return;
    if( a->_left)
        fstream << "\t" + a->_root.toString() + " -> \"" + a->_left->_root.toString() + "\"\n";
    ecritSommet(a->_left, fstream);
    if( a->_right)
        fstream << "\t" + a->_root.toString() + " -> \"" + a->_right->_root.toString() + "\"\n";
    ecritSommet(a->_right, fstream);
}

/*
 * This method put the binary tree discription in a file
 * that allow the rule of digraphz. 
 */
void ArbreB::genereArbreB()
{
    ofstream fstream("tree.dot", ofstream::trunc | ofstream::in);

    fstream << "digraph binaryTree{\n";
    fstream << "\tnode [fontname=\"Arial\"];\n";
    ecritSommet(this, fstream);
    fstream << "}";
    fstream.close();
}

/*
 * This method add a tree top in the binary tree.
 */
void ArbreB::operator<(const Sommet & sommet)
{
    if( !this->_root.getNbOc() ) 
    {
        *this = *(new ArbreB(sommet));
    }
    else
    {
        int nbOc = sommet.getNbOc() + this->_root.getNbOc();
        ArbreB *newArbreB = new ArbreB(Sommet(-1, nbOc));
        newArbreB->_right = new ArbreB();
        *newArbreB->_right = *this;
        newArbreB->_left = new ArbreB(sommet);
        *this = *newArbreB;
    }   
}

void ArbreB::deleteArbreB(ArbreB *arbreB)
{
    // Bug
    /*if( arbreB )
    {
        cout << "In delete .." << endl;
        deleteArbreB(arbreB->_left);
        deleteArbreB(arbreB->_right);
    }
    delete arbreB;*/
}

