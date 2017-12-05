#include "include/database.h"

DataBase::DataBase(QObject* parent)
    : QObject(parent)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("database.db");
    _db.open();
}
