#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QPainterPath>
#include <QPainter>
#include <QCoreApplication>
#include <QPushButton>
#include <QPushButton>
#include <QVBoxLayout>


class Shape : public QWidget
{
public:
    Shape(QWidget *parent = nullptr) : QWidget(parent) {}
    virtual void paintEvent(QPaintEvent *event) = 0;
};

class Circle : public Shape
{
public:
    Circle(QWidget *parent = nullptr) : Shape(parent) {}

    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        painter.drawEllipse(rect());
    }
};

class Hexagon : public Shape
{
public:
    Hexagon(QWidget *parent = nullptr) : Shape(parent) {}

    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::green);

        QVector<QPointF> hexagonPoints;
        int sideLength = qMin(width(), height()) / 2; // Длина стороны шестиугольника
        QPointF center(width() / 2, height() / 2);    // Центр шестиугольника

        for (int i = 0; i < 6; i++)
        {
            qreal angle = 2.0 * M_PI * (i + 0.5) / 6.0;
            qreal x = center.x() + sideLength * cos(angle);
            qreal y = center.y() + sideLength * sin(angle);
            hexagonPoints.append(QPointF(x, y));
        }

        painter.drawPolygon(hexagonPoints.data(), hexagonPoints.size());
    }
};

class Astroid : public Shape
{
public:
    Astroid(QWidget *parent = nullptr) : Shape(parent) {setFixedSize(400, 400);}

    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setBrush(Qt::black);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.translate(width() / 2, height() / 2);

        int size = 70; // Размер фигуры

        QPainterPath path;

        for (int angle = 0; angle <= 360; ++angle) {
            qreal x = size * pow(cos(qDegreesToRadians(angle)), 3);
            qreal y = -size * pow(sin(qDegreesToRadians(angle)), 3);
            path.lineTo(x, y);
        }

        painter.drawPath(path);
    }
};


void quit() {
    QCoreApplication::quit();
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    QVBoxLayout layout(&window);

    window.setWindowTitle("Фигуры");

    Circle circle(&window);
    circle.setGeometry(200,200, 200, 200);

    Hexagon hexagon(&window);
    hexagon.setGeometry(200, 40, 100, 100);

    Astroid astroid(&window);
    astroid.setGeometry(100, 20, 30, 30);

    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        static int circleDirection = 1;   // Направление движения окружности
        static int hexagonDirection = 1;  // Направление движения шестиугольника
        static int astroidDirection = 1;  // Направление движения астроиды

        int circleSpeed = 2;    // Скорость движения окружности
        int hexagonSpeed = 3;   // Скорость движения шестиугольника
        int astroidSpeed = 2;   // Скорость движения астроиды

        int circleDistance = 300;   // Расстояние, на которое должна переместиться окружность
        int hexagonDistance = 420;  // Расстояние, на которое должен переместиться шестиугольник
        int astroidDistance = 240;  // Расстояние, на которое должна переместиться астроида

        int circleX = circle.x() + circleDirection * circleSpeed;
        int hexagonX = hexagon.x() + hexagonDirection * hexagonSpeed;
        int astroidX = astroid.x() + astroidDirection * astroidSpeed;

        if (circleX >= circleDistance || circleX <= 0)
            circleDirection *= -1;  // Разворот направления движения окружности

        if (hexagonX >= hexagonDistance || hexagonX <= 0)
            hexagonDirection *= -1; // Разворот направления движения шестиугольника

        if (astroidX >= astroidDistance || astroidX <= 0)
            astroidDirection *= -1; // Разворот направления движения астроиды
        int circleY =300;
        circle.move(circleX, circleY);
        hexagon.move(hexagonX, hexagon.y());
        astroid.move(astroidX, astroid.y());

        window.update();
    });

    timer.start(10);


    // Создаем стильную кнопку с помощью таблицы стилей CSS
    QPushButton *quitButton = new QPushButton("Exit", &window);
    quitButton->setAttribute(Qt::WA_StyledBackground, true);
    QString buttonStyle = "QPushButton {"
                          "    background-color: #14e6f5;"
                          "    color: black;"
                          "    border: none;"
                          "    border-radius: 50px;"
                          "    padding: 10px 20px;"
                          "}";
    quitButton->setStyleSheet(buttonStyle);

    QObject::connect(quitButton, &QPushButton::clicked, &app, &QApplication::quit);
    layout.addWidget(quitButton);

    window.resize(510, 500);
    window.show();

    return app.exec();
}
