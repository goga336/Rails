#include "datamanager.h"
#include <QDebug>
DataManager::DataManager(QObject *parent) : QObject(parent)
{

}

QStringList DataManager::dataArray() const
{
    return m_dataArray;
}

void DataManager::appendValue(const QString &value)
{
    if (!value.isEmpty()) {
        m_dataArray.append(value);
        emit dataArrayChanged();
    }
}

void DataManager::removeValue(int index)
{
    if (index >= 0 && index < m_dataArray.size()) {
        qDebug() << "removing value at index" << index << "with value" << m_dataArray[index];
        m_dataArray.removeAt(index);
        emit dataArrayChanged();
    }

    qDebug() << "your array:";
    for (int i = 0; i < m_dataArray.size(); i++) {
        qDebug() <<  m_dataArray[i];
    }
}

