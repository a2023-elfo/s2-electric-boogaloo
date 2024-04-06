#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QWidget>
#include <Qdebug>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui {
	class TitleScreen;
}
QT_END_NAMESPACE

class TitleScreen :public  QWidget
{

    Q_OBJECT

public:
    TitleScreen(QWidget* parent = nullptr);
    ~TitleScreen();

public slots:
    void buttonPressed();
signals:
    void changeScreen(int);

private:
    Ui::TitleScreen* ui;

};

#endif