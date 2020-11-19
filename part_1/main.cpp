#include <QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Init the application
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

