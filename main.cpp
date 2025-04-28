// main.cpp
#include "Timer.h"

#ifdef QT_WIDGETS_LIB       // definita da qmake/Qt-cmake se Widgets presente
#include <QApplication>
#include "MainWindow.h"
#else
#include <iostream>
#include <thread>
#endif

int main(int argc, char *argv[])
{
#ifdef QT_WIDGETS_LIB
    /*---------------- GUI Qt ----------------*/
    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("Simple Timer");
    w.resize(300, 150);
    w.show();

    return app.exec();

#else
    /*---------------- Modalità CLI ----------------*/
    std::cout << "=== Simple Timer CLI ===\nInserisci i secondi: ";
    int sec{};
    std::cin >> sec;

    Timer t;
    t.start(sec);

    t.onTick([](int s) {
        std::cout << "Rimangono " << s << " s\r" << std::flush;
    });
    t.onFinish([] {
        std::cout << "\nFatto!\n";
    });

    // attesa finché il timer non termina
    while (t.isRunning())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return 0;
#endif
}

