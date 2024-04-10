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


class MainGUI : public QWidget
{
    Q_OBJECT

public:
    MainGUI(QWidget* parent = nullptr);
    ~MainGUI();
private:
    static const int GRID_X = 5;
    static const int GRID_Y = 10;
    TitleScreen* screen_title;
    Credits* screen_credits;
    GameLoopGUI* screen_game;
    gameOver* gameOver_screen;
    QThread* thread;
    Gameloop* gameloop;

private slots:
    
    void sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets, const Player& player1);
    void changePage(int);
    void updateMoneyGUI(int);
    void updateSuperGUI(int);
    void updateHealthGUI(int);
};
#endif // TEST1_H
