#ifndef DIALOG_H
#define DIALOG_H

#include "block.h"
#include "snake.h"
#include <QDialog>
#include <QColor>
#include <QVector>
#include <QPushButton>
#include <QPoint>
#include <QLabel>


class Dialog : public QDialog {
    Q_OBJECT

    public:
        Dialog(QWidget *parent = 0);
        ~Dialog();

        int getAmountBlocks();
        int getSideLenghtBlock();
        bool isUpdateingColors;
        QColor* getColorBlocks();
        Block* getBlockAt(int x, int y);

    public slots:
        void addEat();

    protected:

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
};

#endif // DIALOG_H
