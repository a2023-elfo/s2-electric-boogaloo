#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{


    screen1 = new TitleScreen(this);
    connect(screen1, &TitleScreen::changeScreen, this, &MainGUI::changePage);
    
    gameloopMap = new GameloopUI(this);


    health = new QProgressBar(this);

    health->setOrientation(Qt::Horizontal);
    health->setFormat(QString("%p health"));
    health->setRange(0, 10);
    health->setValue(10);
    health->setGeometry(QRect(QPoint(10, 10), QSize(300, 25)));

    ui->setupUi(this);
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