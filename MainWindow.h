

#ifndef ELABORATOTIMER_MAINWINDOW_H
#define ELABORATOTIMER_MAINWINDOW_H

#include <QObject>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

#include "Timer.h"   // o forward declaration se vuoi

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
            void toggleTimer();

private:
    static QString format(int sec);
    QLabel *display;
    QLineEdit *input;
    QPushButton *button;
    Timer myTimer;
};

#endif //ELABORATOTIMER_MAINWINDOW_H
