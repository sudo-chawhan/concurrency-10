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
    client.cpp \
    player_teama.cpp \
    player_teamb.cpp \
    mainwindow.cpp \
    dialog.cpp \
    serverscreen.cpp

HEADERS  += \
    game.h \
    player.h \
    bullet.h \
    gamestate.h \
    inputhandler.h \
    server.h \
    client.h \
    player_teama.h \
    player_teamb.h \
    mainwindow.h \
    dialog.h \
    serverscreen.h

FORMS    +=

RESOURCES += \
    rsc.qrc
