#include "dialog.h"
#include "block/block.h"
#include "snake/snake.h"
#include <QTimer>
#include <QColor>
#include <QDebug>
#include <QLabel>
#include <QDir>
#include <QKeyEvent>
#include <QHBoxLayout>

#define RGB_SQUARE   0, 0, 0, 0
#define W_BLOCK_AMOUNT 20
#define H_BLOCK_AMOUNT 20

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    colorBlocks = new QColor(RGB_SQUARE);
    updatedColorSqrCounter = 0;
    blockSideLength = 30;
    amountBlocks = W_BLOCK_AMOUNT * H_BLOCK_AMOUNT;
    blocksStorage = new QVector<Block*>();

    setFixedSize(blockSideLength * W_BLOCK_AMOUNT, blockSideLength * H_BLOCK_AMOUNT);
    //qDebug() << "background: url(\"" + QDir::currentPath() + "/img/bg.jpg\")";
    setStyleSheet("background: url(\"" + QDir::currentPath() + "/img/bg.jpg\")");
    fillByBlocks();

    qDebug() << styleSheet();
    snake = new Snake(this, 0, 0);

//    for ( int  i = 0; i < 2; i++ ) {
//        addEat();
//    }
}

void Dialog::fillByBlocks() {
    for ( int i = 0; i < amountBlocks; i++ ) {
        blocksStorage->append(new Block(colorBlocks, blockSideLength, this));
    }
}

int Dialog::getSideLenghtBlock() const {
    return blockSideLength;
}

QColor* Dialog::getColorBlocks() const {
    return colorBlocks;
}
int Dialog::getAmountBlocks() const {
    return amountBlocks;
}

void Dialog::addEat() {
    int wRand = qrand() % W_BLOCK_AMOUNT;
    int hRand = qrand() % H_BLOCK_AMOUNT;

    getBlockAt(wRand, hRand)->setEat();
}

Block* Dialog::getBlockAt(int x, int y) const {
    return (Block*) childAt(x * blockSideLength, y * blockSideLength);
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
