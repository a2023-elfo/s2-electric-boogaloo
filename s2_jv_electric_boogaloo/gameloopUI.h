#ifndef GAMELOOPUI_H
#define GAMELOOPUI_H

#include <QWidget>
#include <Qdebug>
#include <qpixmap.h>
#include <qlabel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class GameloopUI;
}
QT_END_NAMESPACE

class GameloopUI :public  QWidget
{

    Q_OBJECT

public:
    GameloopUI(QWidget* parent = nullptr);
    ~GameloopUI();

public slots:

signals:

private:
    Ui::GameloopUI* ui;
};

#endif