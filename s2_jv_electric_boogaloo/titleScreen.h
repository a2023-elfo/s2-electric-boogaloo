#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QFont>
#include <QDebug>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
	class TitleScreen;
}
QT_END_NAMESPACE

class TitleScreen :public  QWidget
{

    Q_OBJECT

public:
    TitleScreen(QWidget* parent);
    ~TitleScreen();

public slots:
    void jouerPressed();
    void confirmPressed();
signals:
    void changeScreen(int);

private:
    Ui::TitleScreen* ui;
    QLineEdit* textBox;
};

#endif