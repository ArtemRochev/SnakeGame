#include "dialog.h"
#include "square.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QColor>
#include <QTimer>
#include <math.h>

#define RECT_W 7
#define RECT_H 7

int Square::posX = 0;
int Square::posY = 0;
int Square::counter = 0;

Square::Square(QColor *color, QWidget *parent) : QWidget(parent) {
    setGeometry(posX, posY, RECT_W, RECT_H);
    size = RECT_W;
    posX += RECT_W;
    colorBase = color;
    colorCurrent = colorBase;
    eat = false;
    counter += 1;
    if ( counter % ( (int) sqrt(((Dialog*) parent)->getAmountSquares())) == 0 ) {
        posY += RECT_H;
        posX = 0;
    }
}

void Square::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.setPen(Qt::red);
    p.fillRect(0, 0, 50, 50, QBrush(*colorCurrent));
}

void Square::enterEvent(QEvent*) {
    colorCurrent = new QColor(colorCurrent->dark());
    update();
}
void Square::leaveEvent(QEvent *event) {
    colorCurrent = new QColor(*colorBase);
    update();
}

void Square::mousePressEvent(QMouseEvent*) {
    ((Dialog*) parent())->updateColorsSquares();
}

void Square::setIsEat(bool b) {
    eat = b;
}

void Square::setEat() {
    setColor(rand() % 200, rand() % 200, rand() % 200);
    eat = true;
}

void Square::setColor(QColor *colorNew) {
    colorBase = colorNew;
    colorCurrent = colorBase;
    update();
}
void Square::setColor(int r, int g, int b) {
    colorBase = new QColor(r, g, b);
    colorCurrent = colorBase;
    update();
}

int Square::getSize() {
    return size;
}

bool Square::isEat() {
    return eat;
}

QColor* Square::getColor() {
    return colorCurrent;
}



