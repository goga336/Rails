#include "list.h"

List::List()
{
    dataName = "Data.dat";
    QFile file(dataName);
    file.open(QIODevice::ReadOnly);
    // используем стандартный метод сериализации
    QDataStream in(&file);
    //in.setVersion(QDataStream::Qt_4_0);
    // непосредственно заполняем QList
    picture zap;
    while(!in.atEnd()){
        in >> zap.namePicture;
        in >> zap.authorePicture;
        in >> zap.Year;
        in >> zap.Cluch;
        in >> zap.localePicture;
        Data.push_back(zap);
    }
    file.close();
}
void List::addToList(List::picture pic, QTableWidget* tab){
    Data.push_back(pic);
    int i = tab->rowCount()+1;
    tab->setRowCount(i);
    i--;
    tab->setItem(i, 0, new QTableWidgetItem(pic.namePicture));
    tab->setItem(i, 1, new QTableWidgetItem(pic.authorePicture));
    tab->setItem(i, 2, new QTableWidgetItem(QString::number(pic.Year)));
    tab->setItem(i, 4, new QTableWidgetItem(QString::number(pic.Cluch)));
    tab->setItem(i, 3, new QTableWidgetItem(pic.localePicture));
}

List::~List(){
    QFile file(dataName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for (int i = 0; i < Data.size(); i++){
        out << Data[i].namePicture;
        out << Data[i].authorePicture;
        out << Data[i].Year;
        out << Data[i].Cluch;
        out << Data[i].localePicture;
    }
    file.close();
}

void List::setData(QTableWidget* tab){
    tab->setRowCount(0);
    tab->setRowCount(Data.size());
    for (int i = 0; i < Data.size(); i++){
        tab->setItem(i, 0, new QTableWidgetItem(Data[i].namePicture));
        tab->setItem(i, 1, new QTableWidgetItem(Data[i].authorePicture));
        tab->setItem(i, 2, new QTableWidgetItem(QString::number(Data[i].Year)));
        tab->setItem(i, 3, new QTableWidgetItem(Data[i].localePicture));
        tab->setItem(i, 4, new QTableWidgetItem(QString::number(Data[i].Cluch)));

    }
}

bool List::setData(QTableWidget* tab, int a, int b){
    int row = 0;
    tab->setRowCount(row);
    for (int i = 0; i < Data.size(); i++){
        if(Data[i].Year >= a && Data[i].Year <= b){
            row++;
            tab->setRowCount(row);
            row--;
            tab->setItem(row, 0, new QTableWidgetItem(Data[i].namePicture));
            tab->setItem(row, 1, new QTableWidgetItem(Data[i].authorePicture));
            tab->setItem(row, 2, new QTableWidgetItem(QString::number(Data[i].Year)));
            row++;
        }
    }
    if (row) return true; else return false;
}

QStringList List::hallAuthors(){
    QStringList authors;
    for (int i = 0; i < Data.size(); i++){
        if (Data[i].localePicture == "Зал" && !authors.contains(Data[i].authorePicture)){
            authors.push_back(Data[i].authorePicture);
        }
    }
    return authors;
}

QStringList List::setData(){
    QStringList authors;
    for (int i = 0; i < Data.size(); i++){
        if (Data[i].localePicture == "Запасник" && !authors.contains(Data[i].authorePicture)){
            authors.push_back(Data[i].authorePicture);
        }
    }
    return authors;
}

QString List::value(QString str){
    int i = 0;
    for (auto row: Data){
        if (row.authorePicture == str && row.localePicture == "Запасник") i++;
    }
    return QString::number(i);
};

QStringList List::getData(){
    QStringList authors;
    for (auto row:Data){
        if (!authors.contains(row.authorePicture))
        authors.push_back(row.authorePicture);
    }
    return authors;
}

QList<int> List::getYear(QString aut){
    QList<int> years;
    for (auto row:Data){
        if (row.authorePicture == aut)
        years.push_back(row.Year);
    }
    return years;
}

