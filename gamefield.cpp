#include "gamefield.h"
#include "snake.h"
#include <QLabel>


GameField::GameField(QWidget *parent) : QWidget(parent) {
    setStyleSheet("background: green");
    setFixedSize(100, 100);

    new QLabel("hi", this);
}

GameField::~GameField() {

}

