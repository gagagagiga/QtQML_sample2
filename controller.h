#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class ItemDataList;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(ItemDataList* list, QObject *parent = nullptr);

public slots:
    void startTimer();

    void stopTimer();

private slots:
    void onReadData() ;

signals:


private:
    QTimer _timer;
    ItemDataList* _list;
};

#endif // CONTROLLER_H
