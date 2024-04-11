#ifndef GAMELOOPGUI_H
#define GAMELOOPGUI_H

#include "gameloop.h"

#include <qpushbutton.h>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <qdebug.h>
#include <QWidget>
#include <QSize>
#include <QPalette>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QString>
#include "systemeArgent.h"
#include <qmediaplayer.h>
#include <QAudioOutput>


class GameLoopGUI:public QWidget{
	Q_OBJECT
public:
	GameLoopGUI(QWidget* parent = nullptr);
	~GameLoopGUI();
	QLabel* moneyLabel;
	QProgressBar* healthBar;
	QProgressBar* superBar;
	void stopAudio();

private:
	static const int GRID_X = 5;
	static const int GRID_Y = 10;
	QGridLayout* gridLayout;
	QMediaPlayer* player;
	QAudioOutput* audioOutput;

	//QVBoxLayout* layout;
public slots:
	void afficherGrid();
	void clearGrid();
	void sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets, const Player& player1);
	void afficherSuper();
	void afficherHealt();
	

};

#endif // !GAMELOOPGUI_H

