#pragma once

#include <QWidget>
#include <QLabel>

#include "arbreb.h"

/**
 * MainWindow is a class that represents the main Window
 * It displays an image of the binary tree using QLabel widget.
 * @author: ...(charaf-eddine & aziz fall)...
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

