#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QFont>
#include <QDebug>
#include <QWidget>

#include <Qdebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtWidgets>
#include "enums.h"
#include <QString>




class TitleScreen :public  QWidget
{

    Q_OBJECT

public:
    TitleScreen(QWidget* parent);
    ~TitleScreen();

public slots:
    void creditsPressed();
    void jouerPressed();
    void confirmPressed();
signals:
    void changeScreen(int);
    void PortDeComToGameLoop(QString);
private:
    QLineEdit* textBox;
};

#endif