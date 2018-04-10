#include "include/database.h"
#include <QSqlQuery>
#include <QVariant>

DataBase::DataBase(QObject* parent)
    : QObject(parent)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("database.db");
    _db.open();
}

bool DataBase::createSchema()
{
    QSqlQuery query;
    int localVersion = 0;
    if (query.exec(QStringLiteral(R"(SELECT `value` FROM `system_setting` WHERE `name` = "version";)"))) {
        localVersion = query.value(0).toInt();
    } else {
        localVersion = 0;
    }
}
