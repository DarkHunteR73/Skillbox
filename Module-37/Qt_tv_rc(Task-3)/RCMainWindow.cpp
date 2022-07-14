#include "RCMainWindow.h"

RCMainWindow::RCMainWindow(QWidget *parent) : QMainWindow(parent) {}

void RCMainWindow::add0() {
    channelDisplay->display(0);
}

void RCMainWindow::add1() {
    channelDisplay->display(1);
}

void RCMainWindow::add2() {
    channelDisplay->display(2);
}

void RCMainWindow::add3() {
    channelDisplay->display(3);
}

void RCMainWindow::add4() {
    channelDisplay->display(4);
}

void RCMainWindow::add5() {
    channelDisplay->display(5);
}

void RCMainWindow::add6() {
    channelDisplay->display(6);
}

void RCMainWindow::add7() {
    channelDisplay->display(7);
}

void RCMainWindow::add8() {
    channelDisplay->display(8);
}

void RCMainWindow::add9() {
    channelDisplay->display(9);
}

void RCMainWindow::volumeUp() {
    if ((volumeDisplay->intValue() + 10) <= 100)
        volumeDisplay->display(volumeDisplay->intValue() + 10);
}

void RCMainWindow::volumeDown() {
    if ((volumeDisplay->intValue() - 10) >= 0)
        volumeDisplay->display(volumeDisplay->intValue() - 10);
}

void RCMainWindow::channelUp() {
    if ((channelDisplay->intValue() + 1) <= 9)
        channelDisplay->display(channelDisplay->intValue() + 1);
}

void RCMainWindow::channelDown() {
    if ((channelDisplay->intValue() - 1) >= 0)
        channelDisplay->display(channelDisplay->intValue() - 1);
}
