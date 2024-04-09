#ifndef ZAPAS_H
#define ZAPAS_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QFont>
#include <QHBoxLayout>
#include <QMessageBox>
#include "list.h"

class Zapas : public QDialog
{
    Q_OBJECT
public:
    explicit Zapas(QWidget *parent = nullptr, List* data = nullptr);
    ~Zapas(){delete font; delete value; delete authors;}
    void showCombo();
private:
    QComboBox* authors;
    QLabel* value;
    QFont* font;
    List* Data;
private slots:
    void setText(int num);
};

#endif // ZAPAS_H
