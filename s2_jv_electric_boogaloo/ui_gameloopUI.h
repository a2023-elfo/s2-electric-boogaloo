/********************************************************************************
** Form generated from reading UI file 'gameloopUI.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELOOPUI_H
#define UI_GAMELOOPUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameloopUI
{
public:

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("GameloopUI", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameloopUI: public Ui_GameloopUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELOOPUI_H
