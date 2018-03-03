#-------------------------------------------------
#
# Project created by QtCreator 2018-02-27T15:22:43
#
#-------------------------------------------------

QT       += core gui
QT       += websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    bullet.cpp \
    gamestate.cpp \
    inputhandler.cpp \
    server.cpp \
    client.cpp

HEADERS  += \
    game.h \
    player.h \
    bullet.h \
    gamestate.h \
    inputhandler.h \
    server.h \
    client.h

FORMS    +=

RESOURCES += \
    rsc.qrc
