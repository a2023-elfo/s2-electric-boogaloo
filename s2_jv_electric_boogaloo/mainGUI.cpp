#include "ui_mainGUI.h"
#include "mainGUI.h"

MainGUI::MainGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainGUI)
{
    connect(this, SIGNAL (testsignals()), this, SLOT (testslots()));

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
