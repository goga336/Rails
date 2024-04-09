#include "window.h"
#include "qapplication.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* window = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(window);
    QVBoxLayout* VLay = new QVBoxLayout();
    QFrame* addframe = new QFrame();
    QFrame* interactiveframe = new QFrame();
    QVBoxLayout* addlay = new QVBoxLayout(addframe);
    QVBoxLayout* interactiveLay = new QVBoxLayout(interactiveframe);
    Table = new QTableWidget();
    data = new List();

    addframe -> setFrameShadow(QFrame::Plain);
    addframe -> setFrameShape(QFrame::Box);
    interactiveframe -> setFrameShadow(QFrame::Plain);
    interactiveframe -> setFrameShape(QFrame::Box);

    Table->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    TableConst();
    data->setData(Table);
    QLabel* addLabel = new QLabel("Действия с базой данных");
    QLabel* interactiveLabel = new QLabel("Получение информации о картинах в базе");
    QPushButton* add = new QPushButton("Добавить картину");
    QPushButton* delAll = new QPushButton("Очистить базу данных");
    QPushButton* pictureHall = new QPushButton("Показать перечень художников, чьи работы в экспозиции");
    QPushButton* timePeriod = new QPushButton("Показать названия и авторы картин, за период времени");
    QPushButton* picStoreRoom = new QPushButton("Показать количество работ автора в запаснике");
    QPushButton* authorGrafic = new QPushButton("Построить график количества полотен художника по годам");
    del = new QPushButton("Удать одну или несколько картин из базы");
    del->setEnabled(false);
    addLabel->setAlignment(Qt::AlignCenter);
    addLabel->setStyleSheet("font-size: 12pt; font-weight: bold; color: black");
    interactiveLabel->setAlignment(Qt::AlignCenter);
    interactiveLabel->setStyleSheet("font-size: 12pt; font-weight: bold; color: black");
    interactiveLay->addWidget(interactiveLabel);
    interactiveLay->addWidget(pictureHall);
    interactiveLay->addWidget(timePeriod);
    interactiveLay->addWidget(picStoreRoom);
    interactiveLay->addWidget(authorGrafic);
    interactiveLay->addStretch();
    layout->addWidget(Table);
    addlay->addWidget(addLabel);
    addlay->addWidget(add);
    addlay->addWidget(del);
    addlay->addWidget(delAll);
    addlay->addStretch();
    VLay->addWidget(addframe);
    VLay->addWidget(interactiveframe);
    layout->addLayout(VLay);
    setCentralWidget(window);
    addWindow = new Add_Element();
    hallWindow = new PictureInHall();
    timeWindow = new pictureTimePeriod(nullptr, data);
    zapasWindow = new Zapas(nullptr, data);
    grafWindow = new Graphic(nullptr, data);
    connect(add, SIGNAL(clicked(bool)), this, SLOT(addShow()));
    connect(addWindow, SIGNAL(Ready()), this, SLOT(add()));
    connect(delAll, SIGNAL(clicked(bool)), this, SLOT(clear()));
    connect(Table, SIGNAL(itemSelectionChanged()), this, SLOT(delEnable()));
    connect(del, SIGNAL(clicked(bool)), this, SLOT(delElem()));
    connect(pictureHall, SIGNAL(clicked(bool)), this, SLOT(hall()));
    connect(timePeriod, SIGNAL(clicked(bool)), this, SLOT(time()));
    connect(picStoreRoom, SIGNAL(clicked(bool)), this, SLOT(StoreRoom()));
    connect(authorGrafic, SIGNAL(clicked(bool)), this, SLOT(Graf()));
}

void Window::add(){
    data->addToList(addWindow->getPic(), Table);
    QMessageBox msgBox(QMessageBox::Information, "Добавление картины", "Картина добавлена в галерею!",QMessageBox::Ok); msgBox.exec();
    addWindow->close();
}

void Window::TableConst(){
    QStringList s;
    Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s.push_back("Название картины");
    s.push_back("Автор картины");
    s.push_back("Год написания");
    s.push_back("Местоположение");
    Table->setColumnCount(4);
    Table->setHorizontalHeaderLabels(s);
    Table->setColumnWidth(0, 300);
    Table->setColumnWidth(1, 300);
    Table->setColumnWidth(2, 125);
    Table->setColumnWidth(3, 155);
}

void Window::clear(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Очищение базы данных", "БУДУТ УДАЛЕНЫ ВСЕ ДАННЫЕ О КАРТИНА В ГАЛЕРЕЕ \n Вы уверены?" , QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        data->clear();
        Table->setRowCount(0);
    }
}

void Window::delElem(){

    QModelIndexList selected = Table->selectionModel()->selectedRows();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление элемента/ов из базы", "Выбранные элемент/ы будут удалены \nВы уверены?" , QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
    for (auto row:selected) {
        Table->removeRow(row.row());
        data->delElem(row);
        Table->clearSelection();
    }
    }
}

Window::~Window()
{
    delete Table;
    delete data;
    delete addWindow;
    delete hallWindow;
    delete del;
    delete timeWindow;
    delete zapasWindow;
    delete grafWindow;

}

