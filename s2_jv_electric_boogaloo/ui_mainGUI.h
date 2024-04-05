/********************************************************************************
** Form generated from reading UI file 'mainGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGUI
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *test1)
    {
        if (test1->objectName().isEmpty())
            test1->setObjectName("test1");
        test1->resize(800, 600);
        pushButton = new QPushButton(test1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 200, 83, 29));
        pushButton_2 = new QPushButton(test1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 280, 83, 29));

        retranslateUi(test1);

        QMetaObject::connectSlotsByName(test1);
    } // setupUi

    void retranslateUi(QWidget *test1)
    {
        test1->setWindowTitle(QCoreApplication::translate("MainGUI", "test1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainGUI", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainGUI", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGUI: public Ui_MainGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
