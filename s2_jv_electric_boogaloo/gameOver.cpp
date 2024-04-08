#include "gameOver.h"
#include <QApplication>

gameOver::gameOver(QWidget* parent) :QWidget(parent) {

    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();
    resize(screenSize);

    // Créer les QPushButton pour Play Again et Quit
    playAgainButton = new QPushButton("Play Again", this);
    quitButton = new QPushButton("Quit", this);

    // Connecter les clics des boutons aux slots correspondants
    connect(playAgainButton, SIGNAL(clicked()), this, SLOT(handlePlayAgainClicked()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(handleQuitClicked()));

    QPixmap background("gitgud.png");
    QPixmap etirerBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, etirerBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);


    int buttonWidth = screenWidth / 15;
    int buttonHeight = screenHeight / 30;
    
    quitButton -> setGeometry(((screenWidth - buttonWidth))*9/20, screenHeight / 2, buttonWidth, buttonHeight);
    playAgainButton -> setGeometry(((screenWidth - buttonWidth))*11/20, screenHeight / 2, buttonWidth, buttonHeight);

}

gameOver::~gameOver() {
    delete ui; // Libérer la mémoire allouée pour ui
}

void gameOver::displayScore() {
    // Récupérer le score depuis une source quelconque (par exemple, une variable membre de la classe)
    int score = 8; //pour essayer lol

    // Afficher le score sur l'écran Game Over (par exemple, en utilisant une étiquette)
    scoreLabel->setText("Score: " + QString::number(score));
}

void gameOver::showGameOver() {
    // Afficher l'écran Game Over
    this->show();

    // Afficher le score (s'il est disponible)
    displayScore();

    // Afficher des éléments supplémentaires, tels que des boutons pour rejouer ou quitter le jeu
    playAgainButton->show();
    quitButton->show();
}

void gameOver::handlePlayAgainClicked() {
    //reinitialiser le jeu
    emit changepage(TITLE_SCREEN);
    qDebug() << "Play Again!";
}

void gameOver::handleQuitClicked() {
    QApplication::quit();
    qDebug() << "Quit :(";
}