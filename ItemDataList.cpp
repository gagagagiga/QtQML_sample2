#include "ItemDataList.h"

ItemDataList::ItemDataList(QObject *parent)
    : QObject{parent}
{
    _items.clear();
    createDummyData();
}


int ItemDataList::getCount() const
{
    return _items.count();
}



QVariant ItemDataList::getItemValue(int index, int role)
{
    if (index < 0 || index >= _items.size()) return QVariant();

    switch(role)
    {
    case Role_Bool:     return QVariant(_items[index].valueBool);
    case Role_Int:      return QVariant(_items[index].valueInt);
    case Role_Float:    return QVariant(_items[index].valueFloat);
    case Role_Double:   return QVariant(_items[index].valueDouble);
    case Role_String:   return QVariant(_items[index].valueString);
    default:            return QVariant();
    }
}


bool ItemDataList::setItemValue(int index, int role, const QVariant &value)
{
    if (index < 0 || index >= _items.size()) return false;


    bool changed = true;

    switch (role)
    {
    case Role_Bool:     _items[index].valueBool = value.toBool(); break;
    case Role_Int:      _items[index].valueInt = value.toInt(); break;
    case Role_Float:    _items[index].valueFloat = value.toFloat(); break;
    case Role_Double:   _items[index].valueDouble = value.toDouble(); break;
    case Role_String:   _items[index].valueString = value.toString(); break;
    default:            changed = false; break;
    }

    if(changed) emit dataChanged(index, role);

    return true;
}


int ItemDataList::append(ItemData &item)
{
    emit beginInsertRows();

    _items.append(item);

    int index = (_items.length() - 1);

    emit endInsertRows();

    return index;
}

void ItemDataList::removeAt(int index)
{
    if(index <0 || index >= _items.count()) return;

    emit beginRemoveRows(index);

    _items.removeAt(index);

    emit endRemoveRows();
}

void ItemDataList::removeAll()
{
    emit beginResetModel();

    _items.clear();

    emit endResetModel();
}

void ItemDataList::createDummyData()
{
    for(int i=0; i<10; i++)
    {
        ItemData item;
        item.valueBool = true;
        item.valueInt = i;
        item.valueFloat = i * 0.1;
        item.valueDouble = i * 0.01;
        item.valueString = QString("string %1").arg(i+1);

        _items.append(item);
    }
}
