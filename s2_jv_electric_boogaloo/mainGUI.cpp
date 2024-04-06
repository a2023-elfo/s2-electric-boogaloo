#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    ui->setupUi(this);

    screen1 = new TitleScreen(this);

    connect(screen1, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    
}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::gridUpdate(char grid[5][10])
{
    qInfo()<< "thread parle au main";
}

void MainGUI::changePage(int page) {
    screen1->hide();
    qWarning() << "page change";

    if (page == 1) {
        thread = QThread::create([this] {
            Gameloop gameloop;
            connect(&gameloop, &Gameloop::gridUpdate, this, &MainGUI::gridUpdate);
            gameloop.mainLoop();
            });
        thread->start();
    }
}