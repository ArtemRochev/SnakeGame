#ifndef DIALOG_H
#define DIALOG_H

#include "square.h"
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

        void updateColorsSquares();
        int getAmountSquares();
        int getSizeSquare();
        bool isUpdateingColors;
        QColor* getColorSquares();
        Square* getSquareAt(int x, int y);

    public slots:
        void updateColorNextSquare();
        void setColorAllSquares();
        void addEat();

    protected:

    private:
        int sizeSquare;
        int amountSquares;
        int updatedColorSqrCounter;
        QVector<Square*> *squaresStorage;
        QColor *colorSquares;
        QTimer *timer;
        QTimer *clearTimer;
        QLabel *status;
        QPushButton *buttonClear;
        Snake *snake;
        QPoint currentSnakePos;

        void keyPressEvent(QKeyEvent*);
};

#endif // DIALOG_H
