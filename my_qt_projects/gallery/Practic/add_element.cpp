#include "add_element.h"
#include <QDataStream>
#include <QFile>
#include "window.h"
Add_Element::Add_Element(QWidget *parent)
{
    QVBoxLayout* layName = new QVBoxLayout();
    QVBoxLayout* layAuthor = new QVBoxLayout();
    QVBoxLayout* layYear = new QVBoxLayout();
    QVBoxLayout* layLocale = new QVBoxLayout();
    QVBoxLayout* layCluch= new QVBoxLayout();
    QHBoxLayout* lay = new QHBoxLayout();
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* labelName = new QLabel("Название картины");
    QLabel* labelAuthor = new QLabel("Имя автора");
    QLabel* labelYear = new QLabel("Год написания");
    QLabel* labelLocale = new QLabel("Местоположение");
    QLabel* labelCluch = new QLabel("Срок службы");
    editName = new QLineEdit();
    editAuthor = new QLineEdit();
    spinYear = new QSpinBox();
    spinCluch = new QSpinBox();
    comboLocale = new QComboBox();
    comboLocale->addItem("Зал");
    comboLocale->addItem("Запасник");
    layName->addWidget(labelName);
    layName->addWidget(editName);
    layAuthor->addWidget(labelAuthor);
    layAuthor->addWidget(editAuthor);
    layYear->addWidget(labelYear);
    layYear->addWidget(spinYear);
    layYear->addWidget(labelCluch);
    layYear->addWidget(spinCluch);
    layLocale->addWidget(labelLocale);
    layLocale->addWidget(comboLocale);
    lay->addLayout(layName);
    lay->addLayout(layAuthor);
    lay->addLayout(layYear);
    lay->addLayout(layLocale);
    lay->addLayout(layCluch);
    layout->addLayout(lay);
    spinYear->setRange(1, 2024);
    spinCluch->setRange(1, 2024);
    QPushButton* button = new QPushButton("Добавить");
    layout->addWidget(button);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(add_item()));
}

void Add_Element::add_item(){
    QString strName = editName->text(); QString strAuthor = editAuthor->text();
    int intYear = spinYear->value();
    int intCluch = spinCluch->value();
    if (!strName.isEmpty() && !strAuthor.isEmpty()){
        picture.namePicture = strName;
        picture.authorePicture = strAuthor;
        picture.Year = intYear;
        picture.Cluch = intCluch;
        picture.localePicture = comboLocale->currentText();
        emit Ready();
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Введены некоректные данные, попробуйте еще раз или закройте окно ввода!");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }

}

void Add_Element::clear(){
    editName->clear();
    editAuthor->clear();
    spinYear->clear();
    spinCluch->clear();
}

Add_Element::~Add_Element(){
    delete editName;
    delete editAuthor;
    delete spinYear;
    delete spinCluch;
    delete comboLocale;
}
