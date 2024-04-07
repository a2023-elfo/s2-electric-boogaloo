#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    ui->setupUi(this);

    screen1 = new TitleScreen(this);
    screen2 = new Credits(this);

    connect(screen1, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    connect(screen2, &Credits::changeScreen, this, &MainGUI::changePage);
    screen2->hide();
    screen1->show();
    
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
    screen1->hide();
    screen2->hide();
    qWarning() << "page change";

    if (page == 1) {
        screen1->hide();
        screen2->hide();
        thread = QThread::create([this] {
            Gameloop gameloop;
            connect(&gameloop, &Gameloop::gridUpdate, this, &MainGUI::gridUpdate);
            gameloop.mainLoop();
            });
        thread->start();
    }
    if (page == 2) {
        screen1->hide();
        screen2->show();
    }
    if (page == 3) {
        screen2->hide();
        screen1->show();
    }
}