#include "titleScreen.h"


TitleScreen::TitleScreen(QWidget* parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton("&Click here", this);
    button->setGeometry(QRect(QPoint(600, 525), QSize(200, 50)));
    
    connect(button, &QPushButton::released, this, &TitleScreen::buttonPressed);

    QPushButton* button2 = new QPushButton("&Credits", this);
    button2->setGeometry(QRect(QPoint(300, 525), QSize(200, 50)));

    connect(button2, &QPushButton::released, this, &TitleScreen::creditsButton);

}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::buttonPressed() {
    emit changeScreen(1);
}

void TitleScreen::creditsButton() {
    emit changeScreen(2);
}