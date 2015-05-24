#include "snake.h"
#include "dialog.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

Snake::Snake(QWidget *parent, int x, int y) :
        QWidget(parent),
        size(5),
        slowTime(200),
        currentVec(Right),
        moveTimer(new QTimer()),
        color(new QColor(138, 75, 8)),
        body(new QVector<QPoint*>) {
    setHidden(true);

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveOn()));
    moveToStartPos(x, y);
    moveTimer->start(slowTime);
    qDebug() << "Snake created.";
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

QPoint* Snake::getTailPos() {
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

void Snake::changeVector(Vector vecNew) {
    currentVec = vecNew;
}

void Snake::moveOn() {
    int xChange = 0;
    int yChange = 0;

    if ( currentVec == Up ) {
        yChange = -1;
    } else if ( currentVec == Right ) {
        xChange = 1;
    } else if ( currentVec == Down ) {
        yChange = 1;
    } else if ( currentVec == Left ) {
        xChange = -1;
    }

    moveTo(headPos->x() + xChange, headPos->y() + yChange);
}

void Snake::moveTo(int x, int y) {
    Dialog *dialog = (Dialog*) parent();
    deleteLast();

    if ( getBlockFromDailog(x, y)->isEat() ) {
        size += 1;

        if ( slowTime > 1 ) {
            slowTime -= 5;
            moveTimer->setInterval(slowTime);
        }

        getBlockFromDailog(x, y)->setIsEat(false);
        dialog->addEat();
    } else {
        body->remove(size-1);
    }

    body->push_front(new QPoint(x, y));

    tailPos->setX(body->at(size-1)->x());
    tailPos->setY(body->at(size-1)->y());
    headPos->setX(x);
    headPos->setY(y);

    getBlockFromDailog(x, y)->setColor(color);
}

void Snake::moveToStartPos(int x, int y) {
    if ( x < size ) {
        x = size - 1;
    }

    headPos = new QPoint(x, y);
    tailPos = new QPoint(x+1-size, y);
    headPos->setX(x);
    headPos->setY(y);

    for ( int i = 0; i < size; i++ ) {
        getBlockFromDailog(x - i, y)->setColor(color);
        body->append(new QPoint(getBlockFromDailog(x - i, y)->x() / ((Dialog*) parent())->getSideLenghtBlock(), getBlockFromDailog(x - i, y)->y() / ((Dialog*) parent())->getSideLenghtBlock()));
    }
}

void Snake::deleteLast() {
    getBlockFromDailog(getTailPos())->setColor(((Dialog*) parent())->getColorBlocks());
}












