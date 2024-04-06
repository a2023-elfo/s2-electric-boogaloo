#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>
#include <qthread.h>
#include <Qdebug>
#include "gameloop.h"
#include "titleScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainGUI;
}
QT_END_NAMESPACE

class MainGUI : public QWidget
{
    Q_OBJECT

public:
    MainGUI(QWidget *parent = nullptr);
    ~MainGUI();

private slots:
    void gridUpdate(char grid[5][10]);
    void changePage(int);

private:
    Ui::MainGUI*ui;
    TitleScreen* screen1;
    QThread* thread;
};
#endif // TEST1_H
