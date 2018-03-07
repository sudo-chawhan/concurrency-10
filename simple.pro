#-------------------------------------------------
#
# Project created by QtCreator 2018-02-27T15:22:43
#
#-------------------------------------------------

QT       += core gui
QT       += websockets
QT       += multimedia

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
    dialog.cpp \
    threadpool.cpp \
    serverscreen.cpp \
    hostdialog.cpp \
    clientwindow.cpp \
    gamewindow.cpp \
    global.cpp


HEADERS  += \
    game.h \
    player.h \
    bullet.h \
    gamestate.h \
    inputhandler.h \
    server.h \
    client.h \
    dialog.h \
    threadpool.h\
    serverscreen.h \
    global.h \
    hostdialog.h \
    clientwindow.h \
    gamewindow.h  \
    enums.h


FORMS    += \
    hostdialog.ui \
    clientwindow.ui \
    gamewindow.ui

RESOURCES += \
    rsc.qrc

DISTFILES +=
