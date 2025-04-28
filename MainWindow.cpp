
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QIntValidator>
#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){

    auto *central = new QWidget(this);
    auto *layout  = new QVBoxLayout(central);

    display = new QLabel("00:00:00", this);
    display->setAlignment(Qt::AlignCenter);
    display->setStyleSheet("font-size: 32px; font-weight: bold;");

    input = new QLineEdit(this);
    input->setPlaceholderText("Secondi del timer");
    input->setValidator(new QIntValidator(1, 86400, this));

    button = new QPushButton("Start", this);

    layout->addWidget(display);
    layout->addWidget(input);
    layout->addWidget(button);
    setCentralWidget(central);

    //connessioni tra i bottoni della finestra e l'interfaccia di timer
    connect(button, &QPushButton::clicked, this, &MainWindow::toggleTimer);

    // callback dal thread Timer alla GUI
    myTimer.onTick([this](int sec) {
        QMetaObject::invokeMethod(display, [this, sec] {
            display->setText(format(sec));
        }, Qt::QueuedConnection);
    });

    myTimer.onFinish([this] {
        QMetaObject::invokeMethod(button, [this] {
            button->setText("Start");
        }, Qt::QueuedConnection);
    });
}

void MainWindow::toggleTimer()
{
    if (myTimer.isRunning()) {
        myTimer.stop();
        display->setText("00:00:00");
        button->setText("Start");
        return;
    }

    bool ok = false;
    int secs = input->text().toInt(&ok);
    if (!ok || secs <= 0) return;

    button->setText("Stop");
    myTimer.start(secs);
}


QString MainWindow::format(int sec)
{
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = sec % 60;
    return QStringLiteral("%1:%2:%3")
            .arg(h, 2, 10, QLatin1Char('0'))
            .arg(m, 2, 10, QLatin1Char('0'))
            .arg(s, 2, 10, QLatin1Char('0'));
}