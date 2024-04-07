#include "titleScreen.h"


TitleScreen::TitleScreen(QWidget* parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton("&Click here", this);
    button->setGeometry(QRect(QPoint(600, 525), QSize(200, 50)));
    
    connect(button, &QPushButton::released, this, &TitleScreen::gameplayButton);

    QPushButton* button2 = new QPushButton("&Credits", this);
    button2->setGeometry(QRect(QPoint(300, 525), QSize(200, 50)));

    connect(button2, &QPushButton::released, this, &TitleScreen::creditsButton);

}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::gameplayButton() {
    emit changeScreen(GAMEPLAY_SCREEN);
}

void TitleScreen::creditsButton() {
    emit changeScreen(CREDITS_SCREEN);
}