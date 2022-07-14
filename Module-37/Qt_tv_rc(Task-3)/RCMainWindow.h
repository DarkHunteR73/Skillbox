#ifndef QT_TV_RC_TASK_3__RCMAINWINDOW_H
#define QT_TV_RC_TASK_3__RCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLCDNumber>

class RCMainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit RCMainWindow(QWidget *parent = nullptr);

    QLCDNumber *volumeDisplay{ nullptr };
    QLCDNumber *channelDisplay{ nullptr };

public slots:
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

    void volumeUp();
    void volumeDown();
    void channelUp();
    void channelDown();
};


#endif //QT_TV_RC_TASK_3__RCMAINWINDOW_H
