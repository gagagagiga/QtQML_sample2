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

 
    // 註冊ListModelAAA類別，在QML下可以建立此類型的物件
    qmlRegisterType<ListModelAAA>("UriAAA", 1, 0, "ListModel_AAA");

    // ItemDataList 的實體在C++這建立，
    // ListModelAAA 又需要用到 ItemDataList
    // 因此註冊 ItemDataList 不能在QML下建立此類型的物件，當作參數傳遞用
    qmlRegisterUncreatableType<ItemDataList>("UriAAA", 1, 0, "ItemDataList_AAA",
        QStringLiteral("ItemDataList should not be created in QML"));
    ItemDataList list;

    // Controller主要是C++這端建立的控制物件，
    // 邏輯上是不能在QML下建立，qmlRegisterUncreatableType()可有可無
    qmlRegisterUncreatableType<Controller>("UriAAA", 1, 0, "Controller_AAA",
        QStringLiteral("Controller should not be created in QML"));
    Controller controller(&list);

    //----------------------------------------------------------------
    QQmlApplicationEngine engine;
    //----------------------------------------------------------------

    // 傳遞給QML，供操作物件功能使用
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
