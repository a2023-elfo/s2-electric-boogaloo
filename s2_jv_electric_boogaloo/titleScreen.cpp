#include "titleScreen.h"


TitleScreen::TitleScreen(QWidget* parent): QWidget(parent){

    //Fond d'accueil
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();
    resize(screenSize);

    QPixmap background("images/backgroundcool.png");

    QPixmap etirerBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, etirerBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // Titre
    QLabel* titleLabel = new QLabel("ELFO ELECTRIC BOOGALOO", this);

    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(60);
    titleFont.setFamily("Snap ITC");
    titleLabel->setFont(titleFont);
    
    //jouer bouton
    QPushButton* jouerButton = new QPushButton("JOUER", this);

    int buttonWidthJouer = screenWidth/10;
    int buttonHeightJouer = screenHeight / 12;
    jouerButton->setGeometry((screenSize.width() - buttonWidthJouer) / 2, 5 * screenSize.height() / 10, buttonWidthJouer, buttonHeightJouer);

    jouerButton->setStyleSheet("QPushButton {""background-color: rgba(255, 255, 255, 127);"
        "font-size: 20pt;"
        "border-radius: 10px;"
        "padding: 10px;""}");
    jouerButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    jouerButton->setMaximumSize(800, 800);
    connect(jouerButton, &QPushButton::clicked, this, &TitleScreen::jouerPressed);


    // port de com boite de texte
    textBox = new QLineEdit(this);

    int widthText = screenWidth / 10;
    int heightText = screenHeight / 20;
    textBox->setGeometry((screenSize.width() - widthText) / 2, 6 * screenSize.height() / 10, widthText, heightText);

    //confirmation port de com button

    int widthConfirm = screenWidth / 15;
    int heightConfirm = screenHeight / 25;

    QPushButton* confirmButton = new QPushButton("Confirmation", this);
    confirmButton->setGeometry((screenSize.width() - widthConfirm) / 2, 7 * screenSize.height() / 10, widthConfirm, heightConfirm);
    connect(confirmButton, &QPushButton::clicked, this, &TitleScreen::confirmPressed);

    int widthQuit = screenWidth / 20;
    int heightQuit = screenHeight / 30;

    QPushButton* quitButton = new QPushButton("Quitter", this);
    quitButton->setGeometry((screenSize.width() - widthQuit) / 2, 9 * (screenSize.height() - heightQuit) / 10, widthQuit, heightQuit);
    connect(quitButton, &QPushButton::clicked, this, &TitleScreen::quitPressed);

    int widthCredits = screenWidth / 15;
    int heightCredits = screenHeight / 25;

    QPushButton* creditsButton = new QPushButton("Credits", this);
    creditsButton->setGeometry((screenSize.width() - widthCredits) / 2, 8 * screenSize.height() / 10, widthCredits, heightCredits);
    connect(creditsButton, &QPushButton::clicked, this, &TitleScreen::creditsPressed);

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    this->setLayout(layout);
}


TitleScreen::~TitleScreen()
{
}



void TitleScreen::creditsPressed() {
    emit changeScreen(CREDITS_SCREEN);
}

void TitleScreen::jouerPressed() {
    qDebug() << "JOUER";
    emit changeScreen(GAMEPLAY_SCREEN);
}

void TitleScreen::confirmPressed() {
    QString port = textBox->text();
    qDebug() << "Port de com: " << port;
    emit PortDeComToGameLoop(port);
}

void TitleScreen::quitPressed()
{
    QApplication::quit();
    qDebug() << "Quit :(";
}
