// Copyright (c) 2017 Timur Bairamukov (inagen57@gmail.com)
// Licensed under the GPLv3 license as published by Free Software Foundation.
// https://www.gnu.org/licenses/gpl-3.0-standalone.html

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "include/oneinstancecheck.h"

int main(int argc, char *argv[])
{
    OneInstanceCheck checker("shusai-memory");

    if (!checker.unique()) {
        qDebug() << "Only one instance of the app can be launched.";
        return 1;
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
