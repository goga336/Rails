#ifndef ADD_ELEMENT_H
#define ADD_ELEMENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QMessageBox>
#include "list.h"



class Add_Element : public QDialog
{
    Q_OBJECT
public:
    explicit Add_Element(QWidget *parent = nullptr);
    ~Add_Element();
    List::picture getPic(){return picture;}
    void clear();
protected:
    QLineEdit* editName;
    QLineEdit* editAuthor;
    QSpinBox* spinYear;
    QSpinBox* spinCluch;
    QComboBox* comboLocale;
    List::picture picture;

public slots:
    void add_item();
signals:
    void Ready();
};

#endif // ADD_ELEMENT_H
