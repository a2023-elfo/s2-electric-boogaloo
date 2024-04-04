#include "ui_mainGUI.h"
#include "mainGUI.h"


MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    connect(this, SIGNAL (testsignals()), this, SLOT (testslots()));


    QThread* thread = QThread::create([this] {
        Gameloop gameloop;
        gameloop.mainLoop();
        });
    thread->start();
    ui->setupUi(this);


}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::testslots()
{
    qInfo()<< "thread parle au main";
}
