#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QLabel>
#include <QFrame>
#include "zapas.h"
#include "graphic.h"
#include "pictureinhall.h"
#include "add_element.h"
#include "picturetimeperiod.h"
#include "list.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();
protected:
    void TableConst();
    Add_Element* addWindow;
    PictureInHall* hallWindow;
    pictureTimePeriod* timeWindow;
    Zapas* zapasWindow;
    Graphic* grafWindow;
    QTableWidget* Table;
    QPushButton* del;
    List* data;
    List::picture incPic;
private slots:
    void add();
    void addShow(){addWindow->show(); addWindow->clear();}
    void clear();
    void delEnable(){if (Table->selectionModel()->selectedRows().size() > 0) del->setEnabled(true); else del->setEnabled(false);}
    void delElem();
    void hall(){hallWindow->setAuthor(data); hallWindow->setWindowTitle("Показать перечень художников, чьи работы в экспозиции"); hallWindow->resize(550, 300); hallWindow->show();}
    void time(){timeWindow->setWindowTitle("Показать названия и авторы картин, за период времени"); timeWindow->resize(1025, 300); timeWindow->TableConst(); timeWindow->show();}
    void StoreRoom(){zapasWindow->setWindowTitle("Показать количество работ автора в запаснике"); zapasWindow->resize(500, 100); zapasWindow->show(); zapasWindow->showCombo(); }
            void Graf(){grafWindow->setWindowTitle("Построить график количества полотен художника по годам"); grafWindow->resize(900, 600); grafWindow->setCombo(); grafWindow->show();}
};
#endif // WINDOW_H

