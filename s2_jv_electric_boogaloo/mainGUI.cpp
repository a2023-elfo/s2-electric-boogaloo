#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    ui->setupUi(this);

    screen_title = new TitleScreen(this);
    screen_credits = new Credits(this);

    gameOver_screen = new gameOver(this);
    gameloop = new Gameloop();
    connect(gameloop, &Gameloop::gridUpdate, this, &MainGUI::gridUpdate);
    connect(screen_title, &TitleScreen::PortDeComToGameLoop, gameloop, &Gameloop::recupPortDeComTitleScreen);
    connect(screen_title, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    connect(screen_credits, &Credits::changeScreen, this, &MainGUI::changePage);
    connect(gameOver_screen, &gameOver::changepage, this, &MainGUI::changePage);
    connect(gameloop, &Gameloop::changepage, this, &MainGUI::changePage);


    screen_credits->hide();
    screen_game->hide();
    gameOver_screen->hide();
    screen_title->show();
    
}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::gridUpdate(char grid[GRID_X][GRID_Y])
{
    //qInfo()<< "thread parle au main";
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