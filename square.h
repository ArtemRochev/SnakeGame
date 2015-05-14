#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include <QColor>

class Square : public QWidget {
        Q_OBJECT

    public:
        Square(QColor *color, QWidget *parent = 0);
        void paintEvent(QPaintEvent*);
        void mousePressEvent(QMouseEvent*);
        void enterEvent(QEvent*);
        void leaveEvent(QEvent*);
        void setIsEat(bool b);
        void setEat();
        void setColor(QColor*);
        void setColor(int r, int g, int b);
        int getSize();
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
        int size;
        bool eat;

};

#endif // SQUARE_H
