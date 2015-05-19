#ifndef DIALOG_H
#define DIALOG_H

#include "block/block.h"
#include "snake/snake.h"
#include <QDialog>
#include <QColor>
#include <QVector>
#include <QPushButton>
#include <QPoint>
#include <QLabel>


class Dialog : public QDialog {
    Q_OBJECT

    private:
        int blockSideLength;
        int amountBlocks;
        int updatedColorSqrCounter;
        QVector<Block*> *blocksStorage;
        QColor *colorBlocks;
        QTimer *timer;
        QTimer *clearTimer;
        QPushButton *buttonClear;
        Snake *snake;
        QPoint currentSnakePos;

        void keyPressEvent(QKeyEvent*);

    public:
        Dialog(QWidget *parent = 0);
        ~Dialog();

        void fillByBlocks();
        int getAmountBlocks() const;
        int getSideLenghtBlock() const;
        QColor* getColorBlocks() const;
        Block* getBlockAt(int x, int y) const;

    public slots:
        void addEat();
};

#endif // DIALOG_H
