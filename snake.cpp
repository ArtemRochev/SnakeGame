#include "snake.h"
#include "dialog.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

Snake::Snake(QWidget *parent, int x, int y) : QWidget(parent) {
    setHidden(true);
    timerMoveUp = new QTimer();
    timerMoveDown = new QTimer();
    timerMoveRight = new QTimer();
    timerMoveLeft = new QTimer();
    connect(timerMoveUp, SIGNAL(timeout()), this, SLOT(moveUp()) );
    connect(timerMoveDown, SIGNAL(timeout()), this, SLOT(moveDown()));
    connect(timerMoveRight, SIGNAL(timeout()), this, SLOT(moveRight()));
    connect(timerMoveLeft, SIGNAL(timeout()), this, SLOT(moveLeft()));

    size = 5;
    slowTime = 100;
    body = new QVector<QPoint*>;
    currentVec = Right;
    color = new QColor(100, 0, 100);
    moveToStartPos(x, y);
}

QColor* Snake::getColorBackground() {
    return ((Dialog*) parent())->getColorBlocks();
}

Block* Snake::getBlockFromDailog(QPoint *p) {
    return ((Dialog*) parent())->getBlockAt(p->x(), p->y());
}
Block* Snake::getBlockFromDailog(int x, int y) {
    return ((Dialog*) parent())->getBlockAt(x, y);
}
QPoint* Snake::getHeadPos() {
    return body->at(0);
}
QPoint* Snake::getLastPos() {
    return body->at(size-1);
}
Snake::Vector Snake::getCurrentVec() {
    return currentVec;
}
int Snake::getSize() {
    return size;
}
int Snake::getSlowTime() {
    return slowTime;
}

void Snake::move(Vector vecNew) {
    stopOldTimer(vecNew);
    currentVec = vecNew;
    if ( vecNew == Up ) {
        timerMoveUp->start(slowTime);
    } else if ( vecNew == Down ) {
        timerMoveDown->start(slowTime);
    } else if ( vecNew == Right ) {
        timerMoveRight->start(slowTime);
    } else {
        timerMoveLeft->start(slowTime);
    }

}

void Snake::moveTo(int x, int y) {
    Dialog *dialog = (Dialog*) parent();
    deleteLast();
    if ( getBlockFromDailog(x, y)->isEat() ) {
        size += 1;
        if ( slowTime > 1 ) {
            slowTime -= 5;
        }
        getBlockFromDailog(x, y)->setIsEat(false);
        color = getBlockFromDailog(x, y)->getColor();
        dialog->addEat();
    } else {
        body->remove(size-1);
    }
    body->push_front(new QPoint(x, y));

    lastPos->setX(body->at(size-1)->x());
    lastPos->setY(body->at(size-1)->y());

    headPos->setX(x);
    headPos->setY(y);
    getBlockFromDailog(x, y)->setColor(color);
}

void Snake::moveToStartPos(int x, int y) {
    if ( x < size ) {
        x = size - 1;
    }
    headPos = new QPoint(x, y);
    lastPos = new QPoint(x+1-size, y);
    headPos->setX(x);
    headPos->setY(y);
    for ( int i = 0; i < size; i++ ) {
        getBlockFromDailog(x - i, y)->setColor(color);
        body->append(new QPoint(getBlockFromDailog(x - i, y)->x() / ((Dialog*) parent())->getSideLenghtBlock(), getBlockFromDailog(x - i, y)->y() / ((Dialog*) parent())->getSideLenghtBlock()));
    }
}

void Snake::moveUp() {
    moveTo(headPos->x(), headPos->y() - 1);
}
void Snake::moveDown() {
    moveTo(headPos->x(), headPos->y() + 1);
}

void Snake::moveRight() {
    moveTo(headPos->x() + 1, headPos->y());
}
void Snake::moveLeft() {
    moveTo(headPos->x() - 1, headPos->y());
}

void Snake::stopOldTimer(Vector vecNew) {
    if ( vecNew != currentVec ) {
        if ( currentVec == Up ) {
            timerMoveUp->stop();
        } else if ( currentVec == Down ) {
            timerMoveDown->stop();
        } else if ( currentVec == Right ) {
            timerMoveRight->stop();
        } else {
            timerMoveLeft->stop();
        }
    }
}

void Snake::deleteLast() {
    getBlockFromDailog(getLastPos())->setColor(((Dialog*) parent())->getColorBlocks());
}












