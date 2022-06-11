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

    Q_INVOKABLE int getCount() const;

    QVariant getItemValue(int index, int role);
    bool setItemValue(int index, int role, const QVariant &value);

    int append(ItemData &item);

    Q_INVOKABLE void removeAt(int index);

    Q_INVOKABLE void removeAll();

public slots:

    void createDummyData();

    bool isChecked(int index);

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

};

#endif // ITEMDATALIST_H
