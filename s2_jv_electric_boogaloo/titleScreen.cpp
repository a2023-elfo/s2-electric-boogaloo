#include "titleScreen.h"


TitleScreen::TitleScreen(QWidget* parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton("&Click here", this);
    button->setGeometry(QRect(QPoint(600, 525), QSize(200, 50)));
    
    connect(button, &QPushButton::released, this, &TitleScreen::buttonPressed);

}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::buttonPressed() {
    emit changeScreen(1);
}