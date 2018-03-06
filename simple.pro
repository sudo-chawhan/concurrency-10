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
    dialog.cpp \
    threadpool.cpp \
    serverscreen.cpp \
    wall.cpp \
<<<<<<< HEAD
    hostdialog.cpp \
    clientwindow.cpp \
    gamewindow.cpp \
=======
>>>>>>> feature3
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
    wall.h \
    global.h \
<<<<<<< HEAD
    hostdialog.h \
    clientwindow.h \
    gamewindow.h  \
=======
>>>>>>> feature3
    enums.h


FORMS    += \
    hostdialog.ui \
    clientwindow.ui \
    gamewindow.ui

RESOURCES += \
    rsc.qrc
