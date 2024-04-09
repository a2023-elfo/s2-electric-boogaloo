#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>
#include <qthread.h>
#include <Qdebug>
#include "gameloop.h"
#include "titleScreen.h"
#include "credits.h"
#include "gameLoopGUI.h"
#include "gameOver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainGUI;
}
QT_END_NAMESPACE

class MainGUI : public QWidget
{
    Q_OBJECT

public:
    MainGUI(QWidget* parent = nullptr);
    ~MainGUI();
private:
    Ui::MainGUI* ui;
    static const int GRID_X = 5;
    static const int GRID_Y = 10;
    TitleScreen* screen_title;
    Credits* screen_credits;
    GameLoopGUI* screen_game;
    gameOver* gameOver_screen;
    QThread* thread;
    Gameloop* gameloop;

private slots:
    void gridUpdate(char grid[GRID_X][GRID_Y]);
    void changePage(int);
    void updateSuperGUI(int);
    void updateHealthGUI(int);
};
#endif // TEST1_H
