#include "gameLoopGUI.h"

GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    gridLayout = new QGridLayout(this);
    layout = new QVBoxLayout(this);
    setLayout(layout);
    afficherGrid();
}

GameLoopGUI::~GameLoopGUI(){
}

void GameLoopGUI::clearGrid() {
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        }
        delete item;
    }
}

void GameLoopGUI::gridUpdate(char grid[GRID_X][GRID_Y])
{
    
}

void GameLoopGUI::sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets) {
    qInfo() << "thread vectors parle au gameGUI";
    clearGrid();

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();

    QWidget* gridContainer = new QWidget(this);
    gridContainer->setFixedSize(screenSize.width() / 1.5, screenSize.height() / 1.1);

    QGridLayout* gridLayout = new QGridLayout(gridContainer);

    // Add enemies
    for (size_t i = 0; i < enemies.size(); ++i) {
        const Enemy& enemy = enemies[i];
        qInfo() << "enemies are here";
        QLabel* enemyLabel = new QLabel;
        QPixmap enemyPixmap("Images/zombie1.png");
        QSize newSize = enemyPixmap.size() * 25;
        enemyPixmap = enemyPixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        enemyLabel->setPixmap(enemyPixmap);
        int x = enemy.getX();
        int y = enemy.getY();
        gridLayout->addWidget(enemyLabel, x, y);
        qInfo() << y;
    }

    // Add other elements (pea shooters, potatoes, bullets) at the same cell as enemies
    for (size_t i = 0; i < peaShooters.size(); ++i) {
        const PeaShooter& shooter = peaShooters[i];
        QLabel* shooterLabel = new QLabel;
        QString shooterImagePath = QString::fromStdString("Images/peaShooter.png");
        QPixmap shooterPixmap(shooterImagePath);
        QSize newSize = shooterPixmap.size() * 25; // Make 25 times bigger
        shooterPixmap = shooterPixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        shooterLabel->setPixmap(shooterPixmap);
        int x = shooter.getX();
        int y = shooter.getY();
        gridLayout->addWidget(shooterLabel, x, y);
    }

    for (size_t i = 0; i < potatoes.size(); ++i) {
        const Potato& potato = potatoes[i];
        QLabel* potatoLabel = new QLabel;
        QString potatoImagePath = QString::fromStdString("Images/noix.png");
        QPixmap potatoPixmap(potatoImagePath);
        QSize newSize = potatoPixmap.size() * 25; // Make 25 times bigger
        potatoPixmap = potatoPixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        potatoLabel->setPixmap(potatoPixmap);
        int x = potato.getX();
        int y = potato.getY();
        gridLayout->addWidget(potatoLabel, x, y);
    }

    for (size_t i = 0; i < bullets.size(); ++i) {
        qInfo() << "I NEED MORE BULLETS";
        const Bullet& bullet = bullets[i];
        QLabel* bulletLabel = new QLabel;
        QString bulletImagePath = QString::fromStdString("Images/bullets.png");
        QPixmap bulletPixmap(bulletImagePath);
        QSize newSize = bulletPixmap.size() * 25; // Make 25 times bigger
        bulletPixmap = bulletPixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        bulletLabel->setPixmap(bulletPixmap);
        int x = bullet.getX();
        int y = bullet.getY();
        gridLayout->addWidget(bulletLabel, x, y);
    }

    // Similar code for potatoes and bullets

    gridContainer->setLayout(gridLayout);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(gridContainer);
    layout->setAlignment(gridContainer, Qt::AlignCenter);
    setLayout(layout);
}

void GameLoopGUI::afficherGrid() {

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    QPixmap background("images/game.png");

    QPixmap stretchedBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, stretchedBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->resize(screenSize);

    /*QWidget* gridContainer = new QWidget(this);
    gridContainer->setFixedSize(screenSize.width() / 1.5, screenSize.height() / 1.1);
    QGridLayout* gridLayout = new QGridLayout(gridContainer);

    int newHeight = screenSize.height() / 12;
    int newWidth;

    gridContainer->setLayout(gridLayout);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(gridContainer);
    layout->setAlignment(gridContainer, Qt::AlignCenter); // Align gridContainer to center
    setLayout(layout);*/
}

