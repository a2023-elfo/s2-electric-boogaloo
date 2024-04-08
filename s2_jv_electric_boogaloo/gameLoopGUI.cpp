#include "gameLoopGUI.h"

GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    afficherGrid();
}

GameLoopGUI::~GameLoopGUI(){
}

void GameLoopGUI::afficherGrid(){
    // Set up background image
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    QPixmap background("images/game.png");
    QPixmap stretchedBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, stretchedBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    this->resize(screenSize);

    // Create a new grid layout and set it for this widget
    QGridLayout* gridLayout = new QGridLayout(this);

    int currentRow = 0;
    int currentColumn = 0;

    // Loop to populate the grid with images
    for (int i = 1; i <= 50; ++i) {
        QLabel* imageLabel = new QLabel;
        QPixmap pixmap("images/Elfo_rest.png"); // Ensure this path is correct
        if (pixmap.isNull()) {
            qDebug() << "Failed to load the image: images/Elfo_rest.png";
            continue; // Skip this iteration if the image failed to load
        }
        pixmap = pixmap.scaled(16, 16, Qt::KeepAspectRatio, Qt::FastTransformation);
        imageLabel->setPixmap(pixmap);

        gridLayout->addWidget(imageLabel, currentRow, currentColumn);

        // Update row and column for the next image
        currentColumn++;
        if (currentColumn >= 10) {
            currentColumn = 0;
            currentRow++;
        }
    }
}
