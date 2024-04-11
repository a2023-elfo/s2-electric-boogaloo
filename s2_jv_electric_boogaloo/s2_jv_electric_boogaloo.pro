QT += core gui
QT += widgets
QT += multimedia

######################################################################
# Automatically generated by qmake (3.1) Thu Apr 4 09:47:50 2024
######################################################################

TEMPLATE = vcapp
TARGET = s2_jv_electric_boogaloo
INCLUDEPATH += .

CONFIG  += console
# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x060000 # disables all APIs deprecated in Qt 6.0.0 and earlier

# Input
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

