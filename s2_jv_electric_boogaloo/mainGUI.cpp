#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    ui->setupUi(this);

    screen_title = new TitleScreen(this);
    screen_credits = new Credits(this);

    connect(screen_title, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    connect(screen_credits, &Credits::changeScreen, this, &MainGUI::changePage);
    screen_credits->hide();
    screen_title->show();
    
}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::gridUpdate(char grid[GRID_X][GRID_Y])
{
    qInfo()<< "thread parle au main";
}

void MainGUI::changePage(int page) {
    screen_title->hide();
    screen_credits->hide();
    qWarning() << "page change";

    if (page == GAMEPLAY_SCREEN) {
        screen_title->hide();
        screen_credits->hide();
        thread = QThread::create([this] {
            Gameloop gameloop;
            connect(&gameloop, &Gameloop::gridUpdate, this, &MainGUI::gridUpdate);
            gameloop.mainLoop();
            });
        thread->start();
    }
    else if (page == CREDITS_SCREEN) {
        screen_title->hide();
        screen_credits->show();
    }
    else if (page == TITLE_SCREEN) {
        screen_credits->hide();
        screen_title->show();
    }
}