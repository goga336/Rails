#ifndef PICTURETIMEPERIOD_H
#define PICTURETIMEPERIOD_H

#include <QDialog>
#include <QTableWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QMessageBox>
#include "list.h"

class pictureTimePeriod : public QDialog
{
    Q_OBJECT
public:
    explicit pictureTimePeriod(QWidget *parent = nullptr, List* data = nullptr);
    ~pictureTimePeriod(){delete table; delete ot; delete ddo; delete search;}
    void TableConst();
private:
    List* Data;
    QTableWidget* table;
    QSpinBox* ot, *ddo;
    QPushButton* search;
private slots:
    void searchElem();
};

#endif // PICTURETIMEPERIOD_H
