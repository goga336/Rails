#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QStringList>

class DataManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList dataArray READ dataArray NOTIFY dataArrayChanged)

public:
    explicit DataManager(QObject *parent = nullptr);

    QStringList dataArray() const;

public slots:
    void appendValue(const QString &value);
    void removeValue(int index);

signals:
    void dataArrayChanged();

private:
    QStringList m_dataArray;
};

#endif
