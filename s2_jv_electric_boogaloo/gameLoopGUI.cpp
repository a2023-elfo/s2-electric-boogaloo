#include "gameLoopGUI.h"


GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    setUpdatesEnabled(false);

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();

    gridLayout = new QGridLayout(this);  // Grid layout for the game grid
    int marginSizeHeight = 400;
    int marginSizeWeidth = 60;
    gridLayout->setContentsMargins(marginSizeHeight, marginSizeWeidth, marginSizeHeight, marginSizeWeidth);
    
    afficherGrid();
    afficherSuper();
    afficherHealt();
    setUpdatesEnabled(true);
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


void GameLoopGUI::sendVectors(const std::vector<Enemy>& enemies, const std::vector<PeaShooter>& peaShooters, const std::vector<Potato>& potatoes, const std::vector<Bullet>& bullets, const Player& player1) {   
    
    setUpdatesEnabled(false);
    clearGrid();
  
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    QPixmap background("images/game.png");
    QPixmap stretchedBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, stretchedBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->resize(screenSize);

    static int animationFrame = 0;
    for (int currentRow = 0; currentRow < 10; ++currentRow) {
        for (int currentColumn = 0; currentColumn < 5; ++currentColumn) {
            
            QLabel* imageLabel = new QLabel;
            QPixmap pixmap("images/vide.png");
            if (pixmap.isNull()) {
                qDebug() << "Failed to load the image: images/vide.png";
                continue; // Skip this iteration if the image failed to load
            }
            pixmap = pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
            imageLabel->setPixmap(pixmap);

           
            gridLayout->addWidget(imageLabel, currentRow, currentColumn);

            
            for (int size_z = 0; size_z < enemies.size(); ++size_z) {
                const Enemy& enemy = enemies[size_z];
                if (currentRow == enemy.getY() && currentColumn == enemy.getX()) {
                    QLabel* enemyLabel = new QLabel;
                    
                    QPixmap enemyPixmap(QString("images/zombie%1.png").arg((animationFrame % 3) + 1));
                    if (enemyPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/zombie" << (animationFrame % 3) + 1 << ".png";
                        continue; // Skip this iteration if the image failed to load
                    }
                    enemyPixmap = enemyPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
                    enemyLabel->setPixmap(enemyPixmap);
                    gridLayout->addWidget(enemyLabel, currentRow, currentColumn);
                }
            }

            
            for (int size_b = 0; size_b < bullets.size(); ++size_b) {
                const Bullet& bullet = bullets[size_b];
                if (currentRow == bullet.getY() && currentColumn == bullet.getX()) {
                    QLabel* bulletLabel = new QLabel;
                    QPixmap bulletPixmap("images/bullets.png");
                    if (bulletPixmap.isNull()) {
                        qDebug() << "Failed to load the image: images/bullets.png";
                        continue; 
                    }
                    bulletPixmap = bulletPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
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
                        continue; 
                    }
                    shooterPixmap = shooterPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
                    shooterLabel->setPixmap(shooterPixmap);
                    gridLayout->addWidget(shooterLabel, currentRow, currentColumn);
                }
            }
            for (int size_po = 0; size_po < potatoes.size(); ++size_po) {
                const Potato& potato = potatoes[size_po];
                int health = potato.getHealth();
                
                if (currentRow == potato.getY() && currentColumn == potato.getX()) {
                    if (health > 2) {
                        QLabel* tankLabel = new QLabel;
                        QPixmap tankPixmap("images/noix.png");
                        if (tankPixmap.isNull()) {
                            qDebug() << "Failed to load the image: images/noix.png";
                            continue;
                        }
                        tankPixmap = tankPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
                        tankLabel->setPixmap(tankPixmap);
                        gridLayout->addWidget(tankLabel, currentRow, currentColumn);
                    }
                    else {
                        QLabel* tankLabel = new QLabel;
                        QPixmap tankPixmap("images/noixBobo.png");
                        if (tankPixmap.isNull()) {
                            qDebug() << "Failed to load the image: images/noixBobo.png";
                            continue;
                        }
                        tankPixmap = tankPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
                        tankLabel->setPixmap(tankPixmap);
                        gridLayout->addWidget(tankLabel, currentRow, currentColumn);
                    }
                }
            }
            const Player& player = player1;
            if (currentRow == player.getY() && currentColumn == player.getX()) {
                QLabel* playerLabel = new QLabel;
                QPixmap playerPixmap("images/Elfo_shoot.png");
                
                if (playerPixmap.isNull()) {
                    qDebug() << "Failed to load the image: images/Elfo_shoot.png";
                    continue; 
                }
                playerPixmap = playerPixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation);
                playerLabel->setPixmap(playerPixmap);
                gridLayout->addWidget(playerLabel, currentRow, currentColumn);
            }
        }
    }

    animationFrame = (animationFrame + 1) % 4;
    setLayout(gridLayout);
    setUpdatesEnabled(true);

}

void GameLoopGUI::afficherGrid() {

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    this->resize(screenSize);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    
    systemeArgent systemeArgent;
    moneyLabel = new QLabel("<b>Money: </b>" + QString::number(systemeArgent.checkMoney()), this);
    moneyLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter); 
    moneyLabel->setTextFormat(Qt::RichText);
    moneyLabel->setStyleSheet("font-size: 20px;");
    mainLayout->addWidget(moneyLabel);
}

void GameLoopGUI::afficherSuper(){
    superBar = new QProgressBar(this);
    superBar->setOrientation(Qt::Horizontal);
    superBar->setRange(0, 10);
    superBar->setValue(0);
    
    superBar->setStyleSheet("QProgressBar::chunk { background-color: #0371FF; font-weight: bold; } QProgressBar { font-weight: bold; }");

    superBar->setFormat("Super: %v/%m");
    superBar->setFormat("Super: %v/%m");

    
    superBar->setGeometry(this->width() - 250, 60, 200, 40); 
}

void GameLoopGUI::afficherHealt(){
    healthBar = new QProgressBar(this);
    healthBar->setOrientation(Qt::Horizontal);
    healthBar->setRange(0, 10);
    healthBar->setValue(0);
    healthBar->setStyleSheet("QProgressBar::chunk { background-color: #BE1414; font-weight: bold; } QProgressBar { font-weight: bold; }");
    healthBar->setFormat("Health: %v/%m");

    // Set the geometry of the health progress bar or use layout
    healthBar->setGeometry(this->width() - 250, 10, 200, 40); // You will need to adjust these values
}





