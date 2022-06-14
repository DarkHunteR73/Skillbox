#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>

class ColorfulCircle : public QWidget {
Q_OBJECT
public:
    ColorfulCircle() = default;

    explicit ColorfulCircle(QWidget *parent);

    void paintEvent(QPaintEvent *e) override;

    [[nodiscard]] QSize minimumSizeHint() const override;


public slots:

    void setRed();

    void setYellow();

    void setGreen();

private:
    QPixmap mCurrentCirclePixmap;
    QPixmap mRedCirclePixmap;
    QPixmap mYellowCirclePixmap;
    QPixmap mGreenCirclePixmap;
};

ColorfulCircle::ColorfulCircle(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mYellowCirclePixmap = QPixmap("..\\yellow_circle.png");
    mRedCirclePixmap = QPixmap("..\\red_circle.png");
    mGreenCirclePixmap = QPixmap("..\\green_circle.png");
    mCurrentCirclePixmap = mGreenCirclePixmap;
    setGeometry(mCurrentCirclePixmap.rect());
}

void ColorfulCircle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCirclePixmap);
}

QSize ColorfulCircle::minimumSizeHint() const {
    return { 200, 200 };
}

void ColorfulCircle::setRed() {
    mCurrentCirclePixmap = mRedCirclePixmap;
    update();
}

void ColorfulCircle::setYellow() {
    mCurrentCirclePixmap = mYellowCirclePixmap;
    update();
}

void ColorfulCircle::setGreen() {
    mCurrentCirclePixmap = mGreenCirclePixmap;
    update();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *circle = new ColorfulCircle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int newValue) {
        if (newValue >= 0 && newValue <= 33) circle->setGreen();
        else if (newValue > 33 && newValue <= 66) circle->setYellow();
        else if (newValue > 66 && newValue <= 100) circle->setRed();
    });

    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    window->setFixedSize(200, 250);
    window->show();
    return QApplication::exec();
}

#include <main.moc>