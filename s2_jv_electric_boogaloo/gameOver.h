#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QScreen>
#include <QApplication>
#include <QGUIApplication>

#include "enums.h"


class gameOver : public QWidget {
	Q_OBJECT
public:
	gameOver(QWidget* parent = nullptr);
	~gameOver();

public slots:
	void handlePlayAgainClicked();
	void handleQuitClicked();
	void displayScore(int); //afficher le score
signals:
	void changepage(int);

private:
	QLabel* scoreLabel;
	QLabel* backgroundLabel;
	QPushButton* playAgainButton;
	QPushButton* quitButton;
	int score= 0;
	void showGameOver(); //afficher l'ecran
};

#endif