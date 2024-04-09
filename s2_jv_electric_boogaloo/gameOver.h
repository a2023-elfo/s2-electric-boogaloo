#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include "enums.h"
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
	class gameOver;
}
QT_END_NAMESPACE

class gameOver : public QWidget {
	Q_OBJECT
public:
	gameOver(QWidget* parent = nullptr);
	~gameOver();

public slots:
	void handlePlayAgainClicked();
	void handleQuitClicked();
signals:
	void changepage(int);

private:
	Ui::gameOver* ui;
	QLabel* scoreLabel;
	QLabel* backgroundLabel;
	QPushButton* playAgainButton;
	QPushButton* quitButton;
	void displayScore(); //afficher le score
	void showGameOver(); //afficher l'ecran
};

#endif