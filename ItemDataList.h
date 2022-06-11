#ifndef ITEMDATALIST_H
#define ITEMDATALIST_H

#include <QObject>
#include <QVariant>
#include <QList>

#include "ItemData.h"

class ItemDataList : public QObject
{
    Q_OBJECT
public:
    explicit ItemDataList(QObject *parent = nullptr);


    int getCount() const;

    QVariant getItemValue(int index, int role);
    bool setItemValue(int index, int role, const QVariant &value);

    int append(ItemData &item);
    void removeAt(int index);
    void removeAll();

public slots:


signals:

    // 發送給 QAbstractListModel 的signals
    void beginResetModel();
    void endResetModel();

    void beginInsertRows();
    void endInsertRows();

    void beginRemoveRows(int index);
    void endRemoveRows();

    void dataChanged(int index, int role);

private:
    QList<ItemData> _items;

    void createDummyData();
};

#endif // ITEMDATALIST_H
