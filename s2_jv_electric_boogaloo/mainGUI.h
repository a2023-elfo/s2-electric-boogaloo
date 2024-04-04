#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>
#include <qthread.h>
#include <QTimer>
#include <Qdebug>
#include "gameloop.h"


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
    void testslots();
signals:
    void testsignals();

private:
    Ui::MainGUI*ui;
    QAction *testAction;
};
#endif // TEST1_H
