#include "zapas.h"

Zapas::Zapas(QWidget *parent, List* data)
    : QDialog{parent}
{
    Data = data;
    QHBoxLayout* layout = new QHBoxLayout(this);
    authors = new QComboBox;
    value = new QLabel("");
    font = new QFont();
    font->setBold(true);
    font->setItalic(true);
    font->setPixelSize(50);
    value->setFont(*font);
    value->setAlignment(Qt::AlignCenter);
    layout->addWidget(authors);
    layout->addWidget(value);
    connect(authors, SIGNAL(activated(int)), this, SLOT(setText(int)));
}

void Zapas::showCombo(){
    QStringList s = Data->setData();
    authors->clear();
    authors->addItems(s);
    if (s.isEmpty()) {QMessageBox msgBox(QMessageBox::Information, "Количество работ автора в запаснике", "Работы в запаснике отсутствуют!",QMessageBox::Ok); msgBox.exec(); this->close();}
    value->setText(Data->value(authors->itemText(0)));
}

void Zapas::setText(int num){
    value->setText(Data->value(authors->itemText(num)));
}
