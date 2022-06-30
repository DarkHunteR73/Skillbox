#ifndef QTCALC_TASK_1__CALCMAINWINDOW_H
#define QTCALC_TASK_1__CALCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CalcMainWindow : public QMainWindow {
Q_OBJECT
public:
    QLineEdit *member1Line{ nullptr };
    QLineEdit *member2Line{ nullptr };
    QLineEdit *answerLine{ nullptr };

    explicit CalcMainWindow(QWidget *parent = nullptr);

public slots:
    //Buttons
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void addComma();
    void changeSign();

    //Actions
    void addition();
    void subtraction();
    void multiplication();
    void division();
    void getAnswer();
    void clear();

private:
    QLineEdit **currentLine{ &member1Line };
    double member1{ 0 };
    double member2{ 0 };
    bool commaUsed{ false };
    bool isLocked{ false };

    enum Action {
        NONE,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION
    } currentAction{ NONE };

    void addChar(char);
    void setAction(Action);
    void checkNumber(double &);
};

#endif //QTCALC_TASK_1__CALCMAINWINDOW_H
