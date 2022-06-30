#include <QApplication>
#include "./ui_qtcalc.h"
#include "calcmainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto window = new CalcMainWindow;
    auto calc = new Ui::MainWindow;
    calc->setupUi(window);
    window->member1Line = calc->member1Line;
    window->member2Line = calc->member2Line;
    window->answerLine = calc->answerLine;
    //
    window->show();
    return QApplication::exec();
}
