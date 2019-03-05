#include <QApplication>
#include <QPushButton>
#include "mainFenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainFenetre Fenetre;

    Fenetre.show();

    return app.exec();
}
