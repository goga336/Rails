#include "picturetimeperiod.h"

pictureTimePeriod::pictureTimePeriod(QWidget *parent, List* data)
    : QDialog{parent}
{
    Data = data;
    QFrame* frame = new QFrame();
    QVBoxLayout* buttonLayout = new QVBoxLayout(frame);
    QHBoxLayout* spinOt = new QHBoxLayout();
    QHBoxLayout* spinDdo = new QHBoxLayout();
    QHBoxLayout* spin = new QHBoxLayout();
    QHBoxLayout* layout = new QHBoxLayout(this);

    table = new QTableWidget();
    QLabel* info = new QLabel("Введите период времени (в годах) \n для поиска написанных картин");
    QLabel* otLabel = new QLabel("От");
    ot = new QSpinBox();
    QLabel* ddoLabel = new QLabel("До");
    ddo = new QSpinBox();
    search = new QPushButton("Поиск");
    ot->setRange(1, 2024);
    ddo->setRange(1, 2024);
    spinOt->addWidget(otLabel);
    spinOt->addWidget(ot);
    spinDdo->addWidget(ddoLabel);
    spinDdo->addWidget(ddo);
    spin->addLayout(spinOt);
    spin->addLayout(spinDdo);
    buttonLayout->addStretch();
    buttonLayout->addWidget(info);
    buttonLayout->addLayout(spin);
    buttonLayout->addWidget(search);
    buttonLayout->addStretch();
    layout->addWidget(table);
    layout->addWidget(frame);
    frame -> setFrameShadow(QFrame::Plain);
    frame -> setFrameShape(QFrame::Box);
    TableConst();
    connect(search, SIGNAL(clicked(bool)), this, SLOT(searchElem()));
}

void pictureTimePeriod::TableConst(){
    QStringList s;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s.push_back("Название картины");
    s.push_back("Автор картины");
    s.push_back("Год написания");
    table->setColumnCount(3);
    table->setRowCount(0);
    table->setHorizontalHeaderLabels(s);
    table->setColumnWidth(0, 300);
    table->setColumnWidth(1, 300);
    table->setColumnWidth(2, 125);
}

void pictureTimePeriod::searchElem(){
    bool f;
    if (ot->value() <= ddo->value()){
       f =  Data->setData(table, ot->value(), ddo->value());
    } else {
        f = Data->setData(table, ddo->value(), ot->value());
    }
    if (!f) {QMessageBox msgBox(QMessageBox::Information, "Поиск картин по дате написанния", "В данном промежутке не было написанно картин",QMessageBox::Ok); msgBox.exec();}
}
