#include <iostream>
#include <QTWidgets/QApplication>
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
#include "mainGUI.h"
using json = nlohmann::json;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGUI w;
    w.showFullScreen();

    return a.exec();
}
