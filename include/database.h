#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include "include/event.h"
#include <QObject>
#include <QSqlDatabase>

class DataBase : public QObject {
    Q_OBJECT
public:
    explicit DataBase(QObject* parent = Q_NULLPTR);

    bool addEvent(Event event);
    Event getEvent(int id);
    bool removeEvent(Event event);
    bool commitEvent(Event event);

private:
    QSqlDatabase _db;
    int version;

    bool createSchema();
    bool addTestData();
};
#endif // DATABASE_H
