#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ItemDataList.h"
#include "ListModelAAA.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    //----------------------------------------------------------------
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    //----------------------------------------------------------------


    qmlRegisterType<ListModelAAA>("UriAAA", 1, 0, "ListModel_AAA");

    qmlRegisterUncreatableType<ItemDataList>("UriAAA", 1, 0, "ItemDataList_AAA",
        QStringLiteral("ItemDataList should not be created in QML"));
    ItemDataList list;

    qmlRegisterUncreatableType<Controller>("UriAAA", 1, 0, "Controller_AAA",
        QStringLiteral("Controller should not be created in QML"));
    Controller controller(&list);

    //----------------------------------------------------------------
    QQmlApplicationEngine engine;
    //----------------------------------------------------------------


    engine.rootContext()->setContextProperty("list_AAA", &list);

    engine.rootContext()->setContextProperty("controller_AAA", &controller);

    //----------------------------------------------------------------
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
    //----------------------------------------------------------------
}
