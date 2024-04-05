#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    
    QThread* thread = QThread::create([this] {
        Gameloop gameloop;
        connect(&gameloop, &Gameloop::gridUpdate, this, &MainGUI::gridUpdate);
        gameloop.mainLoop();
        });
    thread->start();
    ui->setupUi(this);


}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::gridUpdate(char grid[5][10])
{
    qInfo()<< "thread parle au main";
}
