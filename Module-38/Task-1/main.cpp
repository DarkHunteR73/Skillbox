#include "imagebutton.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageButton redButton(nullptr);
    redButton.setFixedSize(200, 200);
    redButton.move(800, 400);
    QObject::connect(&redButton, &QPushButton::clicked, [](){ std::cout << "Click!" << std::endl; });
    redButton.show();
    return a.exec();
}

#include "main.moc"
