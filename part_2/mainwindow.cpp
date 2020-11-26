#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QProcess>
#include <QMessageBox>
#include <QFormLayout>
#include <QDialog>  

MainWindow::MainWindow()
{

    setFixedSize(500, 600);
    _mainLayout = new QHBoxLayout(this);

    // Layout window
    QHBoxLayout *cryptageTextLayout = new QHBoxLayout;
    QVBoxLayout *cryptageLayout = new QVBoxLayout;

    // init properties
    _textCrypte = new QTextEdit;
    _textCharge = new QTextEdit;
    _textCharge->setReadOnly(true);
    _textCrypte->setReadOnly(true);
    _chargeFichierBtn = new QPushButton("Charger un fichier");
    _img = new QLabel("Img");
    _crypteTextBtn = new QPushButton("Crypt text");
    _textACrypte = new QLineEdit("Put your text please");


    // add a Horizontal layout composed button and textEdit. (1)
    cryptageTextLayout->addWidget(_textACrypte);
    cryptageTextLayout->addWidget(_crypteTextBtn);

    // add Layout (1) and widget QPushButton in a Vertical Layout.
    cryptageLayout->addWidget(_chargeFichierBtn);
    cryptageLayout->addLayout(cryptageTextLayout);

    // add the text to crypt, text crypted , button to crypt in a formLayout.
    cryptageLayout->addWidget(new QLabel("Text to Crypt"));
    cryptageLayout->addWidget(_textCharge);
    cryptageLayout->addWidget(new QLabel("Text Crypted"));
    cryptageLayout->addWidget( _textCrypte);

    _mainLayout->addLayout(cryptageLayout);
    setLayout(_mainLayout);
    setWindowTitle("Cryptage");

    // Connect buttons to there actions
    connect(_chargeFichierBtn, SIGNAL(clicked()), this, SLOT(cryptFile()));
    connect(_crypteTextBtn, SIGNAL(clicked()), this, SLOT(cryptText()));
}


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

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete _img;
    delete _chargeFichierBtn;
    delete _crypteTextBtn;
    delete _textACrypte;
    delete _textCharge;
    delete _textCrypte;
}


/**
 * @brief crypt a File
 */
void MainWindow::cryptFile()
{
    QString nameFile = QFileDialog::getSaveFileName(this, tr("Upload file"), "", tr("Text files (*.txt)"));
    _crypt = Cryptage(nameFile.toStdString());
    afficheImg();
}


/**
 * @brief MainWindow::cryptText
 */
void MainWindow::cryptText()
{
    _crypt = Cryptage(_textACrypte->text().toStdString(), _textACrypte->text().toStdString().length());

    if( _textACrypte->text().toStdString() == "Put your text please" || _textACrypte->text().trimmed().length() <= 1)
    {
        QMessageBox::warning(this, "No text", "Please, type a text.");
    }
    else
        afficheImg();
}

/**
 * @brief display an image on a window
 */
void MainWindow::afficheImg()
{
    QProcess::execute("dot tree.dot -Tpng -o tree.png");
    loadImg(QString("tree.png"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(_img);
    QDialog *dialog = new QDialog(this);
    dialog->setLayout(layout);
    dialog->show();
    dialog->setWindowTitle("Arbre Binaire");
    _textCrypte->setText(_crypt.getDonneesCryptees());
    _textCharge->setText(_crypt.getTextes());
}

