#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setWindowTitle("Картинная галерея");
    w.resize(1373, 600);
    w.show();
    return a.exec();
}
