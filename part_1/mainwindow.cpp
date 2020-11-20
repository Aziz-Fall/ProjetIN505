#include "mainwindow.h"
#include <QImageReader>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QProcess>

using namespace std;

MainWindow::MainWindow()
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create two binary trees
    ArbreB *arbreB = new ArbreB;
    ArbreB *arbreB2 = new ArbreB;

    //Adding nodes
    *arbreB < make_pair('B', 2);
    *arbreB < make_pair('G', 2);
    *arbreB < make_pair('A', 4);
    *arbreB < make_pair('D', 6);
    
    *arbreB2 < make_pair('I', 2);
    *arbreB2 < make_pair('J', 2);
    *arbreB2 < make_pair('K', 4);

    //Mergin arbreB and arbreB2
    ArbreB *f = *arbreB2 + *arbreB;

    cout << "is A(1) in tree: " << f->recherche(Sommet(make_pair('A', 1))) << endl;

    f->genereArbreB();

    cout << "***Decomposition de l'arbre***" << endl;
    vector<pair<char, int>> sommets = f->decomposeArbre();
    for( size_t i(0); i < sommets.size(); i++)
    {
        cout << sommets[i].first << " --> " << sommets[i].second << endl;
    }
    cout << "******************************" << endl;
    f->genereArbreB();
    delete f;

    // Genere an image.
    QProcess::execute("dot tree.dot -Tpng -o tree.png");

    loadImg("tree.png");
    mainLayout->addWidget(_img);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
    setWindowTitle("Arbre Binaire");
}

//Constructs a pixmap from the file with the given fileName.
/**
* This method load an image with
* the given name fileName
* @param fileName: image's name.
*/
void MainWindow::loadImg(const QString & nameFile)
{
    _img = new QLabel();
    _img->setPixmap(QPixmap(nameFile));
}

MainWindow::~MainWindow() { delete _img;}
