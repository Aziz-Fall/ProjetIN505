#include "cryptage.h"
#include <QProcess>

using namespace std;

/**
 * @brief Cryptage::Cryptage
 */
Cryptage::Cryptage(): _nomFichier(""), _donneesCryptees(""), _arbreB(nullptr)
{

}

/**
 * @brief Cryptage::Cryptage
 * @param textACrypte
 * @param size
 */
Cryptage::Cryptage(std::string textACrypte, int size)
{
    if( size > 0 )
    {
        ofstream flux("file.txt");
        if( !flux.is_open() )
        {
            cout << "Cant open file" << endl;
            return;
        }

        flux << textACrypte;
        flux.close();
        _nomFichier = "file.txt";
        _initMap();
        map<char, int>::iterator itMap;
        for( itMap = _mapOc.begin(); itMap!= _mapOc.end(); itMap++)
            _pq.push(new ArbreB(Sommet(make_pair(itMap->first, itMap->second))));

        _construitArbreB();
        _cryptDonnees();
        _arbreB->genereArbreB();
        delete _arbreB;

        QProcess::execute("rm -f file.txt");
    }
}
/**
 * @brief Cryptage::Cryptage
 * @param nomFichier
 */
Cryptage::Cryptage(std::string nomFichier):_nomFichier(nomFichier), _arbreB(nullptr)
{
    _initMap();
    map<char, int>::iterator itMap;
    for( itMap = _mapOc.begin(); itMap!= _mapOc.end(); itMap++)
        _pq.push(new ArbreB(Sommet(make_pair(itMap->first, itMap->second))));

    _construitArbreB();
    _cryptDonnees();
    _arbreB->genereArbreB();

    delete _arbreB;
}

/**
 * @brief Cryptage::~Cryptage destructor
 */
Cryptage::~Cryptage()
{
}

/**
 * @brief count the nomber of occurrente of 
 * each caracter in a file
 */
void Cryptage::_initMap()
{
    ifstream flux(_nomFichier);
    if( !flux.is_open() )
    {
        cout << "Cant open file" << endl;
        return;
    }

    map<char, int>::iterator endMap;

    char c;
    while(flux.get(c))
    {
        if( endMap != _mapOc.find(c))
            ++_mapOc[c];
        else
            _mapOc[c] = 1;
    }
}

/**
 * @brief buil a binary tree following 
 *  the rule of creating binary tree of algorithm 
 *  huffman
 */
void Cryptage::_construitArbreB()
{
    while( _pq.size() != 1 )
    {
        if( _pq.size() > 1 )
        {
            ArbreB *tmp1 = _pq.top();
            _pq.pop();
            ArbreB *tmp2 = _pq.top();
            _pq.pop();
            ArbreB *f = *tmp1 + *tmp2;
            _pq.push(f);
        }
    }

    _arbreB = _pq.top();
    _pq.pop();
}

/**
 * @brief Take a binary tree and crypt data that it 
 * containes
 * @param racine root of the binary tree
 * @param donneesCryptees
 */
void Cryptage::cryptChar(Sommet *racine, const Sommet & s)
{
    if( !racine ) return;
    else if( racine->getSommet() == s.getSommet() && !racine->getFilsDroite() && !racine->getFilsGauche()) return;
     
    if( racine->recherche(racine->getFilsDroite(), s) )
    {
        _charCryptee[s.getSommet().first].push_back(1);
        cryptChar(racine->getFilsDroite(), s);
    }
    else
    {
        _charCryptee[s.getSommet().first].push_back(0);
        cryptChar(racine->getFilsGauche(), s);
    }
}

/**
 * @brief Crypt data using a binary tree.
 */
void Cryptage::_cryptDonnees()
{
    map<char, int>::iterator itMap;

    for (itMap = _mapOc.begin(); itMap != _mapOc.end();  itMap++)
        cryptChar(_arbreB->getRacine(), Sommet(make_pair(itMap->first, itMap->second)));

    ofstream fluxCoder("textCode.txt");
    ifstream fluxACoder(_nomFichier);

    if( !fluxACoder.is_open() )
    {
        cout << "Cant open file" << endl;
        return;
    }

    if( !fluxCoder.is_open() )
    {
        cout << "Cant open file" << endl;
        return;
    }

    char c;
    while(fluxACoder.get(c) && !fluxCoder.eof())
    {
        _textes.append(c);
        for( size_t i(0); i < _charCryptee[c].size(); i++)
        {
            _donneesCryptees.append(QString::number(_charCryptee[c][i]));
        }
    }

    fluxACoder.close();
    fluxCoder.close();
}

/**
 * @brief return the data crypted
 * @return std::string 
 */
QString Cryptage::getDonneesCryptees()
{
    return _donneesCryptees;
}

/**
 * @brief Cryptage::setNameFile
 * @param nomFichier
 */
void Cryptage::setNameFile(std::string nomFichier) { _nomFichier = nomFichier;}


/**
 * @brief return the attributs _textes
 * 
 * @return std::string 
 */
QString Cryptage::getTextes()
{
    return _textes;
}


/**
 * @brief set textes values.
 * 
 * @param textes 
 */
void Cryptage::setTextes(QString textes)
{
    if( !textes.isEmpty() )
        _textes = textes;
}
