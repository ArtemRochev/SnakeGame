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

#define RGB_SQUARE   0, 0, 0, 60
#define W_BLOCK_AMOUNT 25
#define H_BLOCK_AMOUNT 25
#define EAT_AMOUNT 5

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    colorBlocks = new QColor(RGB_SQUARE);
    updatedColorSqrCounter = 0;
    blockSideLength = 25;
    amountBlocks = W_BLOCK_AMOUNT * H_BLOCK_AMOUNT;
    blocksStorage = new QVector<Block*>();

    setFixedSize(blockSideLength * W_BLOCK_AMOUNT, blockSideLength * H_BLOCK_AMOUNT);
    //qDebug() << "background: url(\"" + QDir::currentPath() + "/img/bg.jpg\")";
    setStyleSheet("background: url(\"" + QDir::currentPath() + "/img/bg.jpg\")");
    fillByBlocks();

    qDebug() << styleSheet();
    snake = new Snake(this, 0, 0);

    //getBlockAt(20, 20)->setEat();

    for ( int  i = 0; i < EAT_AMOUNT; i++ ) {
        addEat();
    }
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
    int wRand = rand() % W_BLOCK_AMOUNT;
    int hRand = rand() % H_BLOCK_AMOUNT;

    getBlockAt(wRand, hRand)->setEat();
}

Block* Dialog::getBlockAt(int x, int y) const {
    return (Block*) childAt(x * blockSideLength, y * blockSideLength);
}

void Dialog::keyPressEvent(QKeyEvent *event) {
    if ( event->key() == Qt::Key_Up ) {
        snake->move(Snake::Up);
    } else if ( event->key() == Qt::Key_Down ) {
        snake->move(Snake::Down);
    } else if ( event->key() == Qt::Key_Right ) {
        snake->move(Snake::Right);
    } else if ( event->key() == Qt::Key_Left ) {
        snake->move(Snake::Left);
    } else if ( event->key() == Qt::Key_Space ) {
        snake->move(snake->getCurrentVec());
    }
}

Dialog::~Dialog() {
    delete snake;
}
