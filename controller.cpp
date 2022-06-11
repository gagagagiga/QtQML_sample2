#include "controller.h"

#include <QTime>
#include <QDebug>
#include <QThread>
#include <QCoreApplication>

#include "ItemData.h"
#include "ItemDataList.h"

Controller::Controller(ItemDataList* list, QObject *parent)
    : QObject{parent}
    , _list(list)
{
     QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(onReadData()));
}

void Controller::startTimer()
{
    _timer.start(100);
}

void Controller::stopTimer()
{
    _timer.stop();
}

void Controller::onReadData()
{
//    qDebug() << qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")) << " -- begin";


    for(int i=0; i<_list->getCount(); i++)
    {

        double value = QTime::currentTime().msec() * 0.01;
        _list->setItemValue(i, Role_Double, QVariant(value));
    }

      // 故意卡住程序
//    QThread::msleep(2000);

//    for(int i=0; i< 2000; i++)
//    {
//        QCoreApplication::processEvents();
//        QThread::msleep(1);
//    }


//    qDebug() << qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")) << " -- end";
}

