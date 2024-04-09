#include "pictureinhall.h"

PictureInHall::PictureInHall(QWidget *parent)
{
    authors = new QTextEdit();
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(authors);
    font = new QFont();
    font->setBold(true);
    font->setItalic(true);
    font->setPixelSize(20);
    authors->setFont(*font);
}

void PictureInHall::setAuthor(List* data){
    QStringList aut;
    aut = data->hallAuthors();
    if (aut.empty()){
        authors->setText("Нет картин в экспозиции");
        return;
    }
    authors->setText("Художники, чьи работы вошли в экспозицию: ");
    for (int i = 0; i < aut.size(); i++){
        authors->append(aut[i]);
    }
}
