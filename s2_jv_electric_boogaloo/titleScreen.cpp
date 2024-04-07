#include "titleScreen.h"


TitleScreen::TitleScreen(QWidget* parent): QWidget(parent){

    //Fond d'accueil
    QPixmap background("image/backgroundcool.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // Titre
    QLabel* titleLabel = new QLabel("ELFO ELECTRIC BOOGALOO", this);

    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(72);
    titleFont.setFamily("Snap ITC");
    titleLabel->setFont(titleFont);

    //jouer bouton
    QPushButton* jouerButton = new QPushButton("JOUER", this);
    jouerButton->setStyleSheet("QPushButton {""background-color: rgba(255, 255, 255, 127);"
        "font-size: 20pt;"
        "border-radius: 10px;"
        "padding: 10px;""}");
    jouerButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    jouerButton->setMaximumSize(800, 800);
    connect(jouerButton, &QPushButton::clicked, this, &TitleScreen::jouerPressed);

    // port de com boite de texte
    textBox = new QLineEdit(this);

    //confirmation port de com button
    QPushButton* confirmButton = new QPushButton("Confirmation", this);
    connect(confirmButton, &QPushButton::clicked, this, &TitleScreen::confirmPressed);

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    layout->addWidget(jouerButton, 0, Qt::AlignCenter);
    layout->addWidget(textBox, 0, Qt::AlignHCenter | Qt::AlignBottom);
    layout->addWidget(confirmButton, 0, Qt::AlignHCenter | Qt::AlignBottom);
    this->setLayout(layout);
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::jouerPressed() {
    qDebug() << "JOUER";
    emit changeScreen(1);
}

void TitleScreen::confirmPressed() {
    QString port = textBox->text();
    qDebug() << "Port de com: " << port;
}