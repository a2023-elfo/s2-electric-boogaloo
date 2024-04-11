QT += core gui
QT += widgets
QT += multimedia

TEMPLATE = vcapp
TARGET = s2_jv_electric_boogaloo
INCLUDEPATH += .

CONFIG  += console
#DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x060000

HEADERS += gameLoopGUI.h \
	   bullet.h \
           displayObject.h \
           enemy.h \
           enums.h \
           gameloop.h \
           grid.h \
           healthBar.h \
	   gameOver.h\
           peaShooter.h \
           plant.h \
           player.h \
           potato.h \
           systemeArgent.h \
           mainGUI.h \
           include/json.hpp \
           titleScreen.h \
	   credits.h\
           include/serial/SerialPort.hpp
SOURCES += gameLoopGUI.cpp \
	   bullet.cpp \
           displayObject.cpp \
           enemy.cpp \
           gameloop.cpp \
	   gameOver.cpp \
           grid.cpp \
           healthBar.cpp \
           peaShooter.cpp \
           plant.cpp \
           player.cpp \
           potato.cpp \
           s2_jv_electric_boogaloo.cpp \
           systemeArgent.cpp \
           titleScreen.cpp \
	   credits.cpp\
           include/serial/SerialPort.cpp \
           mainGUI.cpp

