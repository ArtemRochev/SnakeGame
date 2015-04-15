#include "dialog.h"
#include "square.h"
#include "snake.h"
#include <QTimer>
#include <QColor>
#include <QDebug>
#include <QLabel>
#include <QKeyEvent>
#include <QHBoxLayout>

#define RGB_SQUARE   120, 190, 255
#define TIME_UPDATE_COLOR 1
#define W_SQUARE 7
#define H_SQUARE 7
#define WIN_W 80
#define WIN_H 80

Dialog::Dialog(QWidget *parent) : QDialog(parent), isUpdateingColors(false) {
    colorSquares = new QColor(RGB_SQUARE);
    updatedColorSqrCounter = 0;
    sizeSquare = W_SQUARE;
    amountSquares = WIN_W * WIN_H;
    squaresStorage = new QVector<Square*>();

    for ( int i = 0; i < amountSquares; i++ ) {
        squaresStorage->append(new Square(colorSquares, this));
    }
    status = new QLabel(this);
    sore = 0;
    setStyleSheet("background-color: grey");
    status->setGeometry(0, height() + 80, width() - 80, 20);
    snake = new Snake(this, 0, 0);
    updateStatus();
    for ( int  i = 0; i < 10; i++ ) {
        addEat();
    }
}

void Dialog::updateStatus() {
    status->setText("Очки: " + QString::number(sore * 10) + " ` Размер: " + QString::number(snake->getSize()) + " ` Скорость: " + QString::number((snake->getSlowTime() - 100) * -1) + "%");
}

void Dialog::updateColorsSquares() {

}

int Dialog::getSore() {
    return sore;
}

void Dialog::setSore(int newSore) {
    sore = newSore;
    updateStatus();
}

void Dialog::soreIncrement() {
    sore += 1;
    updateStatus();
}

int Dialog::getSizeSquare() {
    return sizeSquare;
}

QColor* Dialog::getColorSquares() {
    return colorSquares;
}
int Dialog::getAmountSquares() {
    return amountSquares;
}

void Dialog::updateColorNextSquare() {
}
void Dialog::setColorAllSquares() {

}

void Dialog::addEat() {
    int wRand = qrand() % WIN_W;
    int hRand = qrand() % WIN_H;
    getSquareAt(wRand, hRand)->setEat();
}

Square* Dialog::getSquareAt(int x, int y) {
    return (Square*) childAt(x * W_SQUARE, y * H_SQUARE);
}

void Dialog::keyPressEvent(QKeyEvent *event) {
    if ( event->key() == Qt::Key_Up ) {
        snake->move(Snake::Up);
    }
    if ( event->key() == Qt::Key_Down ) {
        snake->move(Snake::Down);
    }
    if ( event->key() == Qt::Key_Right ) {
        snake->move(Snake::Right);
    }
    if ( event->key() == Qt::Key_Left ) {
        snake->move(Snake::Left);
    }
    if ( event->key() == Qt::Key_Space ) {
        snake->move(snake->getCurrentVec());
    }
}

Dialog::~Dialog() {
    delete snake;
}
