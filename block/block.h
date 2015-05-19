#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QColor>
#include <QPixmap>

class Block : public QWidget {
    Q_OBJECT

    private:
        static int posX;
        static int posY;
        static int counter;

        QColor *colorDeault;
        QColor *colorCurrent;
        QPixmap *bgPixmap;
        int sideLength;
        bool eat;

    public:
        Block(QColor *color, int sideLength, QWidget *parent = 0);
        void paintEvent(QPaintEvent*);
        void enterEvent(QEvent*);
        void leaveEvent(QEvent*);
        void setIsEat(bool b);
        void setEat();
        void setColor(QColor*);
        void setColor(int r, int g, int b);
        int getSideLength();
        bool isEat();
        QColor* getColor();
};

#endif // BLOCK_H
