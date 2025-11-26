#-------------------------------------------------
#
# Project created by QtCreator 2025-04-17T20:15:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quizGame
TEMPLATE = app


SOURCES += main.cpp\
    leaderboard.cpp \
        mainwindow.cpp \
    questions.cpp \
    rocketbutton.cpp \
    user.cpp

HEADERS  += mainwindow.h \
    leaderboard.h \
    questions.h \
    rocketbutton.h \
    user.h

FORMS    += mainwindow.ui \
    leaderboard.ui
