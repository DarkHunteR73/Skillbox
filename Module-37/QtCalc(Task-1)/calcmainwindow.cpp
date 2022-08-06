#include "calcmainwindow.h"

CalcMainWindow::CalcMainWindow(QWidget *parent) : QMainWindow(parent) {}

void CalcMainWindow::add0() { addChar('0'); }

void CalcMainWindow::add1() { addChar('1'); }

void CalcMainWindow::add2() { addChar('2'); }

void CalcMainWindow::add3() { addChar('3'); }

void CalcMainWindow::add4() { addChar('4'); }

void CalcMainWindow::add5() { addChar('5'); }

void CalcMainWindow::add6() { addChar('6'); }

void CalcMainWindow::add7() { addChar('7'); }

void CalcMainWindow::add8() { addChar('8'); }

void CalcMainWindow::add9() { addChar('9'); }

void CalcMainWindow::addComma() {
    if (isLocked) return;

    if (!commaUsed) {
        addChar(',');
        commaUsed = true;
    }
}

void CalcMainWindow::changeSign() {
    if (isLocked) return;

    if (!((*currentLine)->text() == "0")) {
        if ((*currentLine)->text().front() == '-')
            (*currentLine)->setText((*currentLine)->text().remove(0, 1));
        else
            (*currentLine)->setText((*currentLine)->text().prepend('-'));
    }
}

void CalcMainWindow::addition() {
    checkNumber(member1);
    setAction(ADDITION);
    (*answerLine).setText("<ADDITION>");
}

void CalcMainWindow::subtraction() {
    checkNumber(member1);
    setAction(SUBTRACTION);
    (*answerLine).setText("<SUBTRACTION>");
}

void CalcMainWindow::multiplication() {
    checkNumber(member1);
    setAction(MULTIPLICATION);
    (*answerLine).setText("<MULTIPLICATION>");
}

void CalcMainWindow::division() {
    checkNumber(member1);
    setAction(DIVISION);
    (*answerLine).setText("<DIVISION>");
}

void CalcMainWindow::getAnswer() {
    isLocked = true;
    checkNumber(member2);

    switch (currentAction) {
        case ADDITION:
            answerLine->setText(QString::number(member1 + member2, 'f', 12).replace('.', ','));
            break;
        case SUBTRACTION:
            answerLine->setText(QString::number(member1 - member2, 'f', 12).replace('.', ','));
            break;
        case MULTIPLICATION:
            answerLine->setText(QString::number(member1 * member2, 'f', 12).replace('.', ','));
            break;
        case DIVISION:
            if (member2 != 0)
                answerLine->setText(QString::number(member1 / member2, 'f', 12).replace('.', ','));
            else
                answerLine->setText("<ERROR>");
            break;
        default:
            answerLine->setText("<NO ACTION>");
    }
}

void CalcMainWindow::clear() {
    member1Line->setText("0");
    member2Line->setText("0");
    answerLine->setText("0");

    currentLine = &member1Line;
    currentAction = NONE;

    member1 = 0;
    member2 = 0;
    commaUsed = false;
    isLocked = false;
}

void CalcMainWindow::addChar(char ch) {
    if (isLocked) return;

    if ((*currentLine)->text() == "0" && ch != ',')
        (*currentLine)->setText(static_cast<QString>(ch));
    else
        (*currentLine)->setText((*currentLine)->text() + ch);
}

void CalcMainWindow::setAction(CalcMainWindow::Action action = NONE) {
    currentAction = action;
    currentLine = &member2Line;
    commaUsed = false;
}

void CalcMainWindow::checkNumber(double &num) {
    QString tmp{ (*currentLine)->text() };
    int pointIndex = tmp.indexOf(',');
    if (pointIndex > 0) {
        tmp[pointIndex] = '.';

        int tailIndex{ tmp.length() - 1 };
        int count{ 0 };
        for (int i = tailIndex; i > 0; --i) {
            if (tmp[i] == '0') {
                tailIndex = i;
                ++count;
            } else if (tmp[i] == '.') {
                tailIndex = i;
                ++count;
                pointIndex = -1;
                break;
            } else { break; }
        }
        if (count > 0)
            tmp.remove(tailIndex, count);
    }

    num = tmp.toDouble();

    (*currentLine)->setText(QString::number(num, 'g',
                                            (pointIndex > 0 ? tmp.length() - 1 : tmp.length())
    ).replace('.', ','));
}