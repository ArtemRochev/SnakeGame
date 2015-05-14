#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QColor>

class Block : public QWidget {
        Q_OBJECT

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

    signals:

    public slots:

    private:
        QColor *colorBase;
        QColor *colorCurrent;
        static int posX;
        static int posY;
        static int counter;
        int sideLength;
        bool eat;

};

#endif // BLOCK_H
