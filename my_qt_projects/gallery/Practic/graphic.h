#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <math.h>
#include <QWidget>
#include <QComboBox>
#include <QPainter>
#include "list.h"

class Graphic : public QWidget
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = nullptr, List* data = nullptr);
    ~Graphic(){delete authors;}
    void setCombo(){authors->clear(); authors->addItems(Data->getData());}

private:
    List* Data;
    QComboBox* authors;
    QChart* chart;
    QLineSeries* series;
    QChartView *chartView;
    QValueAxis *axisX;;
    QValueAxis *axisY;;



private slots:
    void grafic(int);
};

#endif // GRAPHIC_H
