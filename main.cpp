
#include <QApplication>
#include "MainWindow.h"


int main(int argc, char *argv[]) //argc = 1, argv[0] = "./elaboratoTimer" sono i par. default
{
#ifdef QT_WIDGETS_LIB

    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("Timer");
    w.resize(600, 300);
    w.show();

    return app.exec();

#endif
}

