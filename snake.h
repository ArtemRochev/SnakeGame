#ifndef SNAKE_H
#define SNAKE_H

#include "square.h"
#include <QWidget>
#include <QPoint>
#include <QTimer>
#include <QColor>
#include <QVector>

class Snake : public QWidget {
    Q_OBJECT
    Q_ENUMS(Vector)

    public:
        explicit Snake(QWidget*, int x, int y);
        enum Vector {Up, Down, Right, Left};
        QColor* getColorBackground();
        Square* getSquareFromDailog(QPoint*);
        Square* getSquareFromDailog(int x, int y);
        QPoint* getHeadPos();
        QPoint* getLastPos();
        Vector getCurrentVec();
        int getSize();
        int getSlowTime();
        void move(Vector);
        void moveTo(int x, int y);
        void moveToStartPos(int x, int y);
        void stopOldTimer(Vector);
        void deleteLast();

    private:
        int size;
        int slowTime;
        Vector currentVec;
        QTimer *timerMoveUp;
        QTimer *timerMoveDown;
        QTimer *timerMoveRight;
        QTimer *timerMoveLeft;
        QPoint *headPos;
        QPoint *lastPos;
        QColor *color;
        QVector<QPoint*>*body;

    signals:
        void posChanged();

    public slots:
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
};

#endif // SNAKE_H