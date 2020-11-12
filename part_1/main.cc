#include <iostream>

#include "ArbreB.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ArbreB *arbreB = new ArbreB();
    Sommet s1('B', 2), s2('C', 3);
    *arbreB < s1;
    *arbreB < s2;
    *arbreB < Sommet('A', 4);
    *arbreB < Sommet('D', 6);
    *arbreB < Sommet('E', 13);
    *arbreB < Sommet('G', 8);
    arbreB->genereArbreB();
    //arbreB->~ArbreB();
    return 0;
}
