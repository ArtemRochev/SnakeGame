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
        sideLength(sideLength) {
    setGeometry(posX, posY, sideLength, sideLength);
    posX += sideLength;
    qDebug() << "GG";
    eat = false;
    counter += 1;

    if ( counter % ( (int) sqrt(((Dialog*) parent)->getAmountBlocks())) == 0 ) {
        posY += sideLength;
        posX = 0;
    }
}

void Block::paintEvent(QPaintEvent*) {
    QPainter p(this);

    //p.setPen(Qt::red);
    //p.fillRect(0, 0, 50, 50, QBrush(*colorCurrent));
    //qDebug() << QDir::currentPath() + "/img/bg.png";
    //qDebug() << *colorCurrent;

//    if ( *colorCurrent == *colorDeault ) {
//       p.drawPixmap(this->rect(), *bgPixmap);
//    } else {
    p.fillRect(0, 0, 50, 50, QBrush(*colorCurrent));
//    }
}

void Block::enterEvent(QEvent*) {
    colorCurrent = new QColor(0,0,0,100);
    update();
}
void Block::leaveEvent(QEvent*) {
    colorCurrent = colorDeault;
    update();
}

void Block::setIsEat(bool b) {
    eat = b;
}

void Block::setEat() {
    setColor(255, 0, 0);
    eat = true;
}

void Block::setColor(QColor *colorNew) {
    qDebug() << "setColor()";
    //qDebug() << *colorNew;
    colorCurrent = colorNew;
    update();
    //colorCurrent = colorDeault;
}
void Block::setColor(int r, int g, int b) {
    //colorBase = new QColor(r, g, b);
    //colorCurrent = colorBase;
    //update();
}

int Block::getSideLength() {
    return sideLength;
}

bool Block::isEat() {
    return eat;
}

QColor* Block::getColor() {
    //return colorCurrent;
}



