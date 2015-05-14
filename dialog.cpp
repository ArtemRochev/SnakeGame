#include "dialog.h"
#include "block.h"
#include "snake.h"
#include <QTimer>
#include <QColor>
#include <QDebug>
#include <QLabel>
#include <QKeyEvent>
#include <QHBoxLayout>

#define RGB_SQUARE   120, 190, 255
#define TIME_UPDATE_COLOR 1
#define W_SQUARE 30
#define H_SQUARE 30
#define WIN_W 15
#define WIN_H 15

Dialog::Dialog(QWidget *parent) : QDialog(parent), isUpdateingColors(false) {
    colorBlocks = new QColor(RGB_SQUARE);
    updatedColorSqrCounter = 0;
    blockSideLength = W_SQUARE;
    amountBlocks = WIN_W * WIN_H;
    blocksStorage = new QVector<Block*>();
    setFixedSize(W_SQUARE * WIN_W, H_SQUARE * WIN_H);

    //for ( int i = 0; i < amountSquares; i++ ) {
        blocksStorage->append(new Block(colorBlocks, W_SQUARE, this));
    //}
    //snake = new Snake(this, 0, 0);
//    for ( int  i = 0; i < 10; i++ ) {
//        addEat();
//    }
}

int Dialog::getSideLenghtBlock() {
    return blockSideLength;
}

QColor* Dialog::getColorBlocks() {
    return colorBlocks;
}
int Dialog::getAmountBlocks() {
    return amountBlocks;
}

void Dialog::addEat() {
    int wRand = qrand() % WIN_W;
    int hRand = qrand() % WIN_H;
    getBlockAt(wRand, hRand)->setEat();
}

Block* Dialog::getBlockAt(int x, int y) {
    return (Block*) childAt(x * W_SQUARE, y * H_SQUARE);
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
