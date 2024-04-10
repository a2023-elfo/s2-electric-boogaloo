#include "gameLoopGUI.h"
#include <QString>
#include "systemeArgent.h"

GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    gridLayout = new QGridLayout(this);
    
    /*layout = new QVBoxLayout(this);
    setLayout(layout);*/
    afficherGrid();
    afficherSuper();
    afficherHealt();
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
   // qInfo() << "thread vectors parle au gameGUI";
    clearGrid();

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    QPixmap background("images/game.png");
    QPixmap stretchedBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, stretchedBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->resize(screenSize);

    for (int currentRow = 0; currentRow < 10; ++currentRow) {
        for (int currentColumn = 0; currentColumn < 5; ++currentColumn) {
            // Create a QLabel for the empty cell
            QLabel* imageLabel = new QLabel;
            QPixmap pixmap("images/vide.png");
            if (pixmap.isNull()) {
                qDebug() << "Failed to load the image: images/vide.png";
                continue; // Skip this iteration if the image failed to load
            }
            pixmap = pixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
            imageLabel->setPixmap(pixmap);

            // Add the empty cell to the grid layout
            gridLayout->addWidget(imageLabel, currentRow, currentColumn);

            // Check if this cell corresponds to an enemy
            for (int size_z = 0; size_z < enemies.size(); ++size_z) {
                const Enemy& enemy = enemies[size_z];
                if (currentRow == enemy.getY() && currentColumn == enemy.getX()) {
                    QLabel* enemyLabel = new QLabel;
                    QPixmap enemyPixmap("images/zombie1.png");
                    if (enemyPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/zombie1.png";
                        continue; // Skip this iteration if the image failed to load
                    }
                    enemyPixmap = enemyPixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
                    enemyLabel->setPixmap(enemyPixmap);
                    gridLayout->addWidget(enemyLabel, currentRow, currentColumn);
                }
            }

            // Check if this cell corresponds to a bullet
            for (int size_b = 0; size_b < bullets.size(); ++size_b) {
                const Bullet& bullet = bullets[size_b];
                if (currentRow == bullet.getY() && currentColumn == bullet.getX()) {
                    QLabel* bulletLabel = new QLabel;
                    QPixmap bulletPixmap("images/bullets.png");
                    if (bulletPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/bullets.png";
                        continue; // Skip this iteration if the image failed to load
                    }
                    bulletPixmap = bulletPixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
                    bulletLabel->setPixmap(bulletPixmap);
                    gridLayout->addWidget(bulletLabel, currentRow, currentColumn);
                }
            }
            for (int size_p = 0; size_p < peaShooters.size(); ++size_p) {
                const PeaShooter& peaShooter = peaShooters[size_p];
                if (currentRow == peaShooter.getY() && currentColumn == peaShooter.getX()) {
                    QLabel* shooterLabel = new QLabel;
                    QPixmap shooterPixmap("images/peaShooter.png");
                    if (shooterPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/peaShooter.png";
                        continue; // Skip this iteration if the image failed to load
                    }
                    shooterPixmap = shooterPixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
                    shooterLabel->setPixmap(shooterPixmap);
                    gridLayout->addWidget(shooterLabel, currentRow, currentColumn);
                }
            }
            for (int size_po = 0; size_po < potatoes.size(); ++size_po) {
                const Potato& potato = potatoes[size_po];
                if (currentRow == potato.getY() && currentColumn == potato.getX()) {
                    QLabel* tankLabel = new QLabel;
                    QPixmap tankPixmap("images/bullets.png");
                    if (tankPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/bullets.png";
                        continue; // Skip this iteration if the image failed to load
                    }
                    tankPixmap = tankPixmap.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
                    tankLabel->setPixmap(tankPixmap);
                    gridLayout->addWidget(tankLabel, currentRow, currentColumn);
                }
            }
        }
    }

    // Set the grid layout for the widget
    setLayout(gridLayout);
    

}

void GameLoopGUI::afficherGrid() {

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    this->resize(screenSize);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Create a QLabel to display the current money
    systemeArgent systemeArgent;
    moneyLabel = new QLabel("<b>Money: </b>" + QString::number(systemeArgent.checkMoney()), this);
    moneyLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // Align the text to the center
    moneyLabel->setTextFormat(Qt::RichText);
    moneyLabel->setStyleSheet("font-size: 20px;");
    mainLayout->addWidget(moneyLabel);
}

void GameLoopGUI::afficherSuper(){
    superBar = new QProgressBar(this);
    superBar->setOrientation(Qt::Horizontal);
    superBar->setRange(0, 10);
    superBar->setValue(0);
    superBar->setStyleSheet("QProgressBar::chunk { background-color: blue; }");
    superBar->setFormat("Super: %v/%m");

    // Set the geometry of the super progress bar or use layout
    superBar->setGeometry(this->width() - 250, 60, 200, 40); // You will need to adjust these values
}

void GameLoopGUI::afficherHealt(){
    healthBar = new QProgressBar(this);
    healthBar->setOrientation(Qt::Horizontal);
    healthBar->setRange(0, 10);
    healthBar->setValue(0);
    healthBar->setStyleSheet("QProgressBar::chunk { background-color: red; }");
    healthBar->setFormat("Health: %v/%m");

    // Set the geometry of the health progress bar or use layout
    healthBar->setGeometry(this->width() - 250, 10, 200, 40); // You will need to adjust these values
}





