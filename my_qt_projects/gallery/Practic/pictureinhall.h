#ifndef PICTUREINHALL_H
#define PICTUREINHALL_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QFont>
#include "list.h"

class PictureInHall : public QDialog
{
    Q_OBJECT
public:
    explicit PictureInHall(QWidget *parent = nullptr);
    ~PictureInHall(){delete authors; delete font;}
    void setAuthor(List*);
private:
    QTextEdit* authors;
    QFont* font;
};

#endif // PICTUREINHALL_H
