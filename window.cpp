#include "window.h"
#include "gamefield.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
    setCentralWidget(new GameField(this));
}

Window::~Window() {

}

