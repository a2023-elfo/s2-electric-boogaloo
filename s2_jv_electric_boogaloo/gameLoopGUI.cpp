#include "gameLoopGUI.h"
#include <QString>
#include "systemeArgent.h"

GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    afficherGrid();
    afficherSuper();
    afficherHealt();
}

GameLoopGUI::~GameLoopGUI(){
}

void GameLoopGUI::afficherGrid(){
    // Set up background image
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    QPixmap background("images/game.png");
    // Assuming the background image should fill the entire screen
    QPixmap stretchedBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, stretchedBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->resize(screenSize);

    // Create a new vertical layout to contain the grid and the money label
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Create a QLabel to display the current money
    systemeArgent systemeArgent;
    moneyLabel = new QLabel("<b>Money: </b>" + QString::number(systemeArgent.checkMoney()), this);
    moneyLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // Align the text to the center
    moneyLabel->setTextFormat(Qt::RichText);
    moneyLabel->setStyleSheet("font-size: 20px;");
    mainLayout->addWidget(moneyLabel);


    // Create a new grid layout and set it for this widget
    QGridLayout* gridLayout = new QGridLayout(this);

    // Determine the new height for the elf images to fit 10 vertically in the screen height
    int newHeight = screenSize.height() / 10;
    int newWidth; // Will be calculated to maintain aspect ratio

    QPixmap elfPixmap("images/Elfo_rest.png");
    if (elfPixmap.isNull()) {
        qDebug() << "Failed to load the image: images/Elfo_rest.png";
    }
    else {
        // Calculate new width to maintain aspect ratio
        double aspectRatio = static_cast<double>(elfPixmap.width()) / elfPixmap.height();
        newWidth = static_cast<int>(newHeight * aspectRatio);
    }

    // Loop to populate the grid with images, 10 per column
    for (int i = 0; i < 50; ++i) {
        QLabel* imageLabel = new QLabel;
        if (!elfPixmap.isNull()) {
            QPixmap scaledPixmap = elfPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::FastTransformation);
            imageLabel->setPixmap(scaledPixmap);
        }

        int currentRow = i % 10; // This will give you the row number 0-9
        int currentColumn = i / 10; // This will give you the column number 0-4
        gridLayout->addWidget(imageLabel, currentRow, currentColumn);
    }

    // Set the grid layout for the widget
    this->setLayout(gridLayout);
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




