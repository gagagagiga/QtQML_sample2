#include "ListModelAAA.h"
#include "ItemDataList.h"

ListModelAAA::ListModelAAA(ItemDataList* list, QObject *parent)
    : QAbstractListModel(parent)
    , _list(list)
{
    beginResetModel();

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
}

// 實作 QAbstractListModel 的 virtual functions -------------------------

int ListModelAAA::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0; // ?
    if (!_list) return 0;

    return _list->getCount();
}

QVariant ListModelAAA::data(const QModelIndex &index, int role) const
{
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
