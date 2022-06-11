#include "ListModelAAA.h"

#include <QDebug>

#include "ItemDataList.h"

ListModelAAA::ListModelAAA(QObject *parent)
    : QAbstractListModel(parent)
    , _list(nullptr)
{

}

// 實作 QAbstractListModel 的 virtual functions -------------------------

int ListModelAAA::rowCount(const QModelIndex &parent) const
{
    //qDebug() << "rowCount()";

    if (parent.isValid()) return 0; // ?
    if (!_list) return 0;

    int count = _list->getCount();
    return count;
}

QVariant ListModelAAA::data(const QModelIndex &index, int role) const
{
    //qDebug() << "data()";

    if (index.isValid() == false) return QVariant();
    if (!_list) return QVariant();

    return _list->getItemValue(index.row(), role);
}

bool ListModelAAA::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!_list) return false;

    return _list->setItemValue(index.row(), role, value);
}

Qt::ItemFlags ListModelAAA::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ListModelAAA::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { Role_Bool,    "roleBool" },
        { Role_Int,     "roleInt" },
        { Role_Float,   "roleFloat" },
        { Role_Double,  "roleDouble" },
        { Role_String,  "roleString" }
    };
    return roles;
}

// 實作 QAbstractListModel 的 virtual functions -------------------------


ItemDataList *ListModelAAA::itemDataList() const
{
    return _list;
}



void ListModelAAA::setItemDataList(ItemDataList *list)
{
    if(!list) return;

    beginResetModel();

    if (_list != nullptr) _list->disconnect(this);

    _list = list;


    connect(_list, &ItemDataList::beginResetModel, this, [=]() {
        beginResetModel();
    });

    connect(_list, &ItemDataList::endResetModel, this, [=]() {
        endResetModel();
    });

    connect(_list, &ItemDataList::beginInsertRows, this, [=]() {
        const int index = _list->getCount();
        beginInsertRows(QModelIndex(), index, index);
    });
    connect(_list, &ItemDataList::endInsertRows, this, [=]() {
        endInsertRows();
    });

    connect(_list, &ItemDataList::beginRemoveRows, this, [=](int index) {
        beginRemoveRows(QModelIndex(), index, index);
    });
    connect(_list, &ItemDataList::endRemoveRows, this, [=]() {
        endRemoveRows();
    });

    connect(_list, &ItemDataList::dataChanged, this, [=](int index, int role){
        emit dataChanged(this->index(index, 0), this->index(index, 0), QVector<int>() << role);
    });

    endResetModel();

    emit itemDataListChanged();
}
