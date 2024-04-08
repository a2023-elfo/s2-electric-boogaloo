#include "gameLoopGUI.h"

GameLoopGUI::GameLoopGUI(QWidget* parent) : QWidget(parent){
    afficherGrid();
}

GameLoopGUI::~GameLoopGUI(){
}

void GameLoopGUI::afficherGrid(){
    qDebug() << "gagabougogofaaofnow";
    // Create a new grid layout
    QGridLayout* gridLayout = new QGridLayout(this); // Set layout for this widget

    // Variables to keep track of the current row and column
    int currentRow = 0;
    int currentColumn = 0;

    // Loop to populate the grid with images
    for (int i = 1; i <= 50; ++i) {
        QLabel* imageLabel = new QLabel;
        QPixmap pixmap(QString(":/images/image%1.png").arg(i));
        pixmap = pixmap.scaled(16, 16, Qt::KeepAspectRatio, Qt::FastTransformation);
        imageLabel->setPixmap(pixmap);

        gridLayout->addWidget(imageLabel, currentRow, currentColumn);

        // Update row and column for next image
        currentColumn++;
        if (currentColumn >= 10) {
            currentColumn = 0;
            currentRow++;
        }
    }
}
