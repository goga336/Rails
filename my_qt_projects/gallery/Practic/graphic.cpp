#include "graphic.h"
#include <QList>

Graphic::Graphic(QWidget *parent, List* data)
{
    Data = data;
    authors = new QComboBox();
    series = new QLineSeries();
    chart = new QChart();
    chart-> addSeries(series);

    axisX = new QValueAxis();
    axisX->setTitleText("Года");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(1);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setTitleText("Картины");
    axisY->setLabelFormat("%g");
    axisY->setTickCount(5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QVBoxLayout* l = new QVBoxLayout(this);
    chartView = new QChartView(chart);
    l->addWidget(chartView);
    l->addWidget(authors);
    this->setCombo();
    //grafic(0);
    connect(authors, SIGNAL(activated(int)), this, SLOT(grafic(int)));
}

void Graphic::grafic(int num){
    QList<int> years = Data->getYear(authors->itemText(num));
    std::sort(years.begin(), years.end());
    QList<int> unicYears;
    QList<int> numYears;
    int valuePic = 0;
    for (auto row:years){
        if (!unicYears.contains(row)) unicYears.push_back(row);
    }
    for (auto row:unicYears){
        numYears.push_back(years.count(row));
        if (years.count(row) > valuePic) valuePic = years.count(row);
    }
    int k = 0;
    qDebug() << unicYears.size();
    series->clear();
    while (k < unicYears.size())
    {
        qDebug() << (int)unicYears[k] << (int)numYears[k];
        *series << QPointF((int)unicYears[k],(int)numYears[k]);
        ++k;
    }
        series->attachAxis(axisX);
        series->attachAxis(axisY);
        axisX->setRange(unicYears[0], unicYears[unicYears.size()-1]);
        axisY->setRange(0, valuePic+1);
        int n = (unicYears[unicYears.size()-1]- unicYears[0]-1)/25;
        //axisX->setTickCount((unicYears[unicYears.size()-1]- unicYears[0]-1)/(n+1));
        axisY->setTickCount(valuePic+2);
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
}

