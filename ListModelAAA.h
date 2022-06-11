#ifndef LISTMODELAAA_H
#define LISTMODELAAA_H

#include <QAbstractListModel>

class ItemDataList;

class ListModelAAA : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModelAAA(ItemDataList* list, QObject *parent = nullptr);

    // 實作 QAbstractListModel 的 virtual functions -------------------------

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QHash<int, QByteArray> roleNames() const override;

    // 實作 QAbstractListModel 的 virtual functions -------------------------

private:
    ItemDataList *_list;

};

#endif // LISTMODELAAA_H
