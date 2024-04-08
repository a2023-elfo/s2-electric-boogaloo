#include "credits.h"


Credits::Credits(QWidget* parent) :QWidget(parent) {
    QSize screenSize = QGuiApplication::primaryScreen()->geometry().size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();

    resize(screenSize);

    setWindowTitle("Credits");
    QVBoxLayout* layout = new QVBoxLayout(this);
    
    textCredits = new QTextEdit(this);
    textCredits->setStyleSheet("background-color: black; color : #802180; border : none;");
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
    this->setStyleSheet("QWidget { background-image: url(Images/backgroundCredits.jpg); }");

}

Credits::~Credits() {
}


void Credits::buttonClicked() {
    emit changeScreen(TITLE_SCREEN);
}


/*int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Credits credits;
    credits.show();
    return app.exec();
}*/