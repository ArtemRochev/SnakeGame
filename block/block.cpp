#include "dialog.h"
#include "block.h"
#include <QPainter>
#include <QDebug>
#include <QDir>
#include <QMouseEvent>
#include <QEvent>
#include <QColor>
#include <QPixmap>
#include <QTimer>
#include <math.h>

int Block::posX = 0;
int Block::posY = 0;
int Block::counter = 0;

Block::Block(QColor *color, int sideLength, QWidget *parent) :
        QWidget(parent),
        colorDeault(new QColor(0,0,0,0)),
        colorCurrent(colorDeault),
        eatPixmap(new QPixmap(QDir::currentPath() + "/img/eat.png")),
        sideLength(sideLength) {
    setGeometry(posX, posY, sideLength, sideLength);
    posX += sideLength;
    eat = false;
    counter += 1;

    if ( counter % ( (int) sqrt(((Dialog*) parent)->getAmountBlocks())) == 0 ) {
        posY += sideLength;
        posX = 0;
    }
}

void Block::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.fillRect(this->rect(), QBrush(*colorCurrent));

    if ( eat ) {
        p.drawPixmap(this->rect(), *eatPixmap);
    }
}

void Block::enterEvent(QEvent*) {
    colorCurrent = new QColor(0,0,0,100);
    update();
}
void Block::leaveEvent(QEvent*) {
    colorCurrent = colorDeault;
    update();
}

void Block::setIsEat(bool eat) {
    this->eat = eat;
    update();
}

void Block::setEat() {
    eat = true;
    update();
}

void Block::setColor(QColor *colorNew) {
    colorCurrent = colorNew;
    update();
}
void Block::setColor(int r, int g, int b) {
    colorCurrent->setRgb(r, g, b);
    update();
}

int Block::getSideLength() {
    return sideLength;
}

bool Block::isEat() {
    return eat;
}
