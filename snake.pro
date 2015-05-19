#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T19:39:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    snake/snake.cpp \
    block/block.cpp

HEADERS  += dialog.h \
    snake/snake.h \
    block/block.h
