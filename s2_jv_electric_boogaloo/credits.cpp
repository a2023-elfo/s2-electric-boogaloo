#include "credits.h"


Credits::Credits(QWidget* parent) :QWidget(parent) {
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();

    resize(screenSize);

    setWindowTitle("Credits");
    QVBoxLayout* layout = new QVBoxLayout(this);
    
    textCredits = new QTextEdit(this);
    textCredits->setStyleSheet("background-color: transparent; color : #8A1474; border : none;");
    textCredits->setAlignment(Qt::AlignCenter);
    QFont font = textCredits->font();
    font.setPointSize(30);
    font.setBold(true);
    textCredits->setFont(font);
    textCredits->setReadOnly(true);

    textCredits->setFixedSize(screenSize);
    textCredits->append("Projet fait par :\nAlyson Bourque \nAnahi Michelle Mongelos Toledo\nJean-Nicholas Gosselin\nJordan Gagnon\nMathieu Mercier\nOlivier Pinard\nWilliam Perron\nZacharie Cameron");

    layout->addWidget(textCredits, 0, Qt::AlignCenter);

    exitButton = new QPushButton("Retourner au jeu", this);
    int buttonWidth = 2*screenWidth/10;
    int buttonHeight = screenHeight/15;

    exitButton->setGeometry((screenSize.width() - buttonWidth) / 2, 6 * screenSize.height() / 10, buttonWidth, buttonHeight);
    QFont buttonFont("Arial", 20, QFont::Bold);
    exitButton->setFont(buttonFont);

    exitButton->setStyleSheet("background-color: green; color: black; border: 2px solid white; border-radius: 8px");
    connect(exitButton, &QPushButton::clicked, this, &Credits::buttonClicked);    
    QPixmap background("Images/backgroundCredits.jpg");
    QPixmap etirerBackground = background.scaled(screenSize, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, etirerBackground);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    int labelWidth = 2* screenWidth / 6;
    int labelHeight = screenHeight / 2;
    QLabel* label = new QLabel(this);
    label->setPixmap(QPixmap("Images/manette.png"));
    label->setGeometry((screenSize.width() - labelWidth) / 10, 6 * screenSize.height() / 10, labelWidth, labelHeight);
}

Credits::~Credits() {
}


void Credits::buttonClicked() {
    emit changeScreen(TITLE_SCREEN);
}