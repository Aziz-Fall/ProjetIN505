#pragma once 


#include <QWidget>
#include <QLabel>

#include "ArbreB.h"

/**
 * MainWindow is a class that represent the main Window
 * It display a image contained a binary tree using QLabel(_img).
 * @author: ...(achraf & aziz fall)...
 * @version: 1.0.0
*/
class MainWindow: public QWidget
{
    private:
        QLabel *_img;
        void loadImg(const QString & nameFile);
    public:
        MainWindow();
        ~MainWindow();
};

