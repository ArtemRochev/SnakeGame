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
        explicit Snake(QWidget*, int x, int y);
        enum Vector {Up, Down, Right, Left};
        QColor* getColorBackground();
        Block* getBlockFromDailog(QPoint*);
        Block* getBlockFromDailog(int x, int y);
        QPoint* getHeadPos();
        QPoint* getLastPos();
        Vector getCurrentVec();

        int getSize();
        int getSlowTime();

        void changeVector(Vector);
        void moveTo(int x, int y);
        void moveToStartPos(int x, int y);
        void stopOldTimer(Vector);
        void deleteLast();

    private:
        int size;
        int slowTime;
        Vector currentVec;
        QTimer *moveTimer;
        QPoint *headPos;
        QPoint *lastPos;
        QColor *color;
        QVector<QPoint*>*body;

    signals:
        void posChanged();

    public slots:
        void moveOn();
};

#endif // SNAKE_H
