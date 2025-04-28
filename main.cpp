// main.cpp
#include "Timer.h"

#ifdef QT_WIDGETS_LIB       // definita da qmake/Qt-cmake se Widgets presente
#include <QApplication>
#include "MainWindow.h"
#else
#include <iostream>
#include <thread>
#endif

int main(int argc, char *argv[]) //argc = 1, argv[0] = "./elaboratoTimer" sono i par. default
{
#ifdef QT_WIDGETS_LIB
    //con finestra
    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("Simple Timer");
    w.resize(600, 300);
    w.show();

    return app.exec();

#endif
}

