#ifndef CREDITS_H
#define CREDITS_H

#include <iostream>
#include <QMainWindow>
#include <QtextEdit>
#include <Qlabel>
#include <QPushButton>
#include <QtWidgets>
#include <QTextEdit>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
	class Credits;
}
QT_END_NAMESPACE

class Credits : public QWidget {

	Q_OBJECT

public:
	Credits(QWidget* parent = nullptr);
	~Credits();
private :
	QTextEdit* textCredits;
	QPushButton* exitButton;
	//Ui::Credits* ui;
public slots:
	void buttonClicked();
signals :
	void changeScreen(int);
};

#endif