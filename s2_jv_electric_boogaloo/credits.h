#ifndef CREDITS_H
#define CREDITS_H

#include <iostream>
#include <QMainWindow>
#include <Qlabel>
#include <QPushButton>
#include <QtWidgets>
#include <QTextEdit>
#include <QPixmap>
#include "enums.h"



class Credits : public QWidget {

	Q_OBJECT

public:
	Credits(QWidget* parent = nullptr);
	~Credits();
private :
	QTextEdit* textCredits;
	QPushButton* exitButton;
	
public slots:
	void buttonClicked();
signals :
	void changeScreen(int);
};

#endif