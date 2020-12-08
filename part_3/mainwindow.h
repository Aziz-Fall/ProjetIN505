#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>

#include "cryptage.h"
#include "decryptage.h"
/**
 * MainWindow is a class that represents the main Window
 * It displays an image of the binary tree using QLabel widget.
 * @author: ...(charaf-eddine & aziz fall)...
 * @version: 1.0.0
*/
class MainWindow: public QWidget
{
    Q_OBJECT

    private:
        QLabel *_img;
        QPushButton *_chargeFichierBtn;
        QPushButton *_crypteTextBtn;
        QPushButton *_dechiffreTextBtn;
        QTextEdit *_textDecrypte;
        QLineEdit *_textACrypte;
        QTextEdit *_textCharge;
        QTextEdit *_textCrypte;
        QHBoxLayout *_mainLayout;

        Cryptage _crypt;

        void loadImg(const QString & nameFile);
        void afficheImg();
    public:
        MainWindow();
        ~MainWindow();

    public slots:
        void cryptFile();
        void cryptText();
        void decrypt();
};

