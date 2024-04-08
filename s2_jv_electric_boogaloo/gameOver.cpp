#include "gameOver.h"
#include <QApplication>

gameOver::gameOver(QWidget* parent) :QWidget(parent) {
    // Créer les QPushButton pour Play Again et Quit
    playAgainButton = new QPushButton("Play Again", this);
    quitButton = new QPushButton("Quit", this);

    // Connecter les clics des boutons aux slots correspondants
    connect(playAgainButton, SIGNAL(clicked()), this, SLOT(handlePlayAgainClicked()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(handleQuitClicked()));

    backgroundLabel = new QLabel(this);
    QPixmap backgroundImage("gitgud.png"); // Utilisez le chemin relatif de votre image de fond
    backgroundLabel->setPixmap(backgroundImage);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());


    // Placer les boutons au-dessus de l'image de fond
    playAgainButton->raise();
    quitButton->raise();

    // Ajuster la géométrie des boutons "Play Again" et "Quit"
    QSize buttonSize(100, 50); // Taille des boutons
    int spacing = 20; // Espacement entre les boutons et le bord de l'écran
    playAgainButton->resize(buttonSize);
    quitButton->resize(buttonSize);

    // Placer les boutons au milieu en bas de l'écran
    int totalWidth = buttonSize.width() * 2 + spacing; // Largeur totale occupée par les boutons et l'espacement
    int startX = (this->width() - totalWidth) / 2; // Position horizontale de départ
    int startY = this->height() - buttonSize.height() - spacing; // Position verticale
    playAgainButton->move(startX, startY);
    quitButton->move(startX + buttonSize.width() + spacing, startY);
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
    qDebug() << "Play Again!";
}

void gameOver::handleQuitClicked() {
    QApplication::quit();
    qDebug() << "Quit :(";
}