#ifndef GAMELOOPGUI_H
#define GAMELOOPGUI_H

#include <qwidget.h>
#include <QtWidgets>
#include <qpushbutton.h>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <qdebug.h>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QPalette>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <QVBoxLayout>

#include "gameloop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameLoopGUI; }
QT_END_NAMESPACE

class GameLoopGUI:public QWidget{
	Q_OBJECT
public:
	GameLoopGUI(QWidget* parent = nullptr);
	~GameLoopGUI();

	void afficherGrid();
	void clearGrid();


private:
	static const int GRID_X = 5;
	static const int GRID_Y = 10;
	QGridLayout* gridLayout;
	QVBoxLayout* layout;

public slots:
	void gridUpdate(char grid[GRID_X][GRID_Y]);
	void sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets);

};

#endif // !GAMELOOPGUI_H

