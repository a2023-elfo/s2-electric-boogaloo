#include "ui_mainGUI.h"
#include "mainGUI.h"
#include "systemeArgent.h"


MainGUI::MainGUI(QWidget* parent)
    : QWidget(parent)
    , screen_title(new TitleScreen(this))
    , screen_credits(new Credits(this))
    , gameOver_screen(new gameOver(this))
    , screen_game(new GameLoopGUI(this))
    , gameloop(new Gameloop())
{
    screen_title->show();
    screen_credits->hide();
    screen_game->hide();
    gameOver_screen->hide();

    connect(gameloop, &Gameloop::sendVectors, screen_game, &GameLoopGUI::sendVectors);
    connect(screen_title, &TitleScreen::PortDeComToGameLoop, gameloop, &Gameloop::recupPortDeComTitleScreen);
    connect(screen_title, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    connect(screen_credits, &Credits::changeScreen, this, &MainGUI::changePage);
    connect(gameOver_screen, &gameOver::changepage, this, &MainGUI::changePage);
    connect(gameloop, &Gameloop::changepage, this, &MainGUI::changePage);
    connect(gameloop, &Gameloop::moneyUpdated, this, &MainGUI::updateMoneyGUI);
    connect(gameloop, &Gameloop::healthUpdateGL, this, &MainGUI::updateHealthGUI);
    connect(gameloop, &Gameloop::superUpdateGL, this, &MainGUI::updateSuperGUI);
    connect(gameloop, &Gameloop::gameOverSignal, gameOver_screen, &gameOver::displayScore);
}

MainGUI::~MainGUI()
{
}

void MainGUI::sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets, const Player& player1){
    qInfo() << "thread vectors parle au main";
}

void MainGUI::changePage(int page) {
    screen_title->hide();
    screen_credits->hide();
    screen_game->hide();
    gameOver_screen->hide();



    qWarning() << "page change";

    if (page == GAMEPLAY_SCREEN) {
        screen_title->hide();
        screen_game->show();
        screen_credits->hide();
        gameOver_screen->hide();
        gameloop->reset();
        thread = QThread::create([this] {
            gameloop->mainLoop();
            });
        thread->start();
    }
    else if (page == CREDITS_SCREEN) {
        screen_title->hide();
        screen_game->hide();
        screen_credits->show();
        gameOver_screen->hide();
    }
    else if (page == TITLE_SCREEN) {
        screen_credits->hide();
        screen_game->hide();
        screen_title->show();
        gameOver_screen->hide();
    }
    else if( page== GAMEOVER_SCREEN) {
        screen_credits->hide();
        screen_title->hide();
        gameOver_screen->show();
    }
}

void MainGUI::updateMoneyGUI(int value) {
    screen_game->moneyLabel->setText("<b>Money: </b>" + QString::number(value));
}
void MainGUI::updateSuperGUI(int value) {
    screen_game->superBar->setValue(value);
}
void MainGUI::updateHealthGUI(int value) {
    screen_game->healthBar->setValue(value);
}