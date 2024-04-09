#ifndef LIST_H
#define LIST_H
#include <QList>
#include <QFile>
#include <QTableWidget>
class List
{
public:
    List();
    ~List();
    struct picture{
        QString namePicture;
        QString authorePicture;
        int Year;
        int Cluch;
        QString localePicture;
    };
    int pictureValue(){return Data.size();}
    void addToList(List::picture, QTableWidget*);
    void setData(QTableWidget*);
    QStringList setData();
    QStringList getData();
    QList<int> getYear(QString);
    QList<int> getCluch(QString);
    bool setData(QTableWidget*, int, int);
    void clear(){Data.clear();}
    void delElem(QModelIndex index) {Data.removeAt(index.row());}
    QStringList hallAuthors();
    QString value(QString);
protected:
    QList<picture> Data;
    QString dataName;
};

#endif // LIST_H
