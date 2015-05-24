#ifndef SNAKE_H
#define SNAKE_H

#include "block/block.h"
#include <QWidget>
#include <QPoint>
#include <QTimer>
#include <QColor>
#include <QVector>

class Snake : public QWidget {
    Q_OBJECT
    Q_ENUMS(Vector)

    public:
      enum Vector {Up, Down, Right, Left};

    private:
        int size;
        int slowTime;
        Vector currentVec;
        QTimer *moveTimer;
        QPoint *headPos;
        QPoint *tailPos;
        QColor *color;
        QVector<QPoint*>*body;

    public:
        explicit Snake(QWidget*, int x, int y);
        QColor* getColorBackground();
        Block* getBlockFromDailog(QPoint*);
        Block* getBlockFromDailog(int x, int y);
        QPoint* getHeadPos();
        QPoint* getTailPos();
        Vector getCurrentVec();

        int getSize();
        int getSlowTime();

        void changeVector(Vector);
        void moveTo(int x, int y);
        void moveToStartPos(int x, int y);
        void stopOldTimer(Vector);
        void deleteLast();

    public slots:
        void moveOn();
};

#endif // SNAKE_H
