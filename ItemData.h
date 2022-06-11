#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QAbstractListModel>

enum ItemRole{
    Role_Bool = Qt::UserRole,
    Role_Int,
    Role_Float,
    Role_Double,
    Role_String,
};

struct ItemData
{
    bool    valueBool;
    int     valueInt;
    float   valueFloat;
    double  valueDouble;
    QString valueString;

    ItemData()
        : valueBool(false)
        , valueInt(0)
        , valueFloat(0)
        , valueDouble(0)
        , valueString("none")
    {

    }
};

#endif // ITEMDATA_H
