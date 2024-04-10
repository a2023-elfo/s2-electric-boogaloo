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
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class GameLoopGUI; }
QT_END_NAMESPACE

class GameLoopGUI:public QWidget{
	Q_OBJECT
public:
	GameLoopGUI(QWidget* parent = nullptr);
	~GameLoopGUI();
	QLabel* moneyLabel;
public slots:
	void afficherGrid();
	void afficherSuper();
	void afficherHealt();

	QProgressBar* healthBar;
	QProgressBar* superBar;
};

#endif // !GAMELOOPGUI_H

