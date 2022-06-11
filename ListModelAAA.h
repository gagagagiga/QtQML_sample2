#ifndef LISTMODELAAA_H
#define LISTMODELAAA_H

#include <QAbstractListModel>

class ItemDataList;

class ListModelAAA : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ItemDataList * itemDataList READ itemDataList WRITE setItemDataList NOTIFY itemDataListChanged)

public:
    explicit ListModelAAA(QObject *parent = nullptr);

    // 實作 QAbstractListModel 的 virtual functions -------------------------

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QHash<int, QByteArray> roleNames() const override;

    // 實作 QAbstractListModel 的 virtual functions -------------------------


    ItemDataList * itemDataList() const;
    void setItemDataList(ItemDataList *list);

signals:
    void itemDataListChanged();

private:
    ItemDataList *_list;

};

#endif // LISTMODELAAA_H
