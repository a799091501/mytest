#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"myexe2.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
 qmlRegisterType<QandA>("io.qt.myexe2.backend", 1, 0, "QandA");
 qmlRegisterType<client>("io.qt.myexe2.client",1,0,"my_client");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
