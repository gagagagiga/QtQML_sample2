#include "controller.h"

#include <QTime>

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

    for(int i=0; i<_list->getCount(); i++)
    {

        double value = QTime::currentTime().msec() * 0.01;
        _list->setItemValue(i, Role_Double, QVariant(value));
    }

}

