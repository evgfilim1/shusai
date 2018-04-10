#ifndef EVENT_H
#define EVENT_H

// Copyright (c) 2017 Timur Bairamukov (inagen57@gmail.com)
// Licensed under the GPLv3 license as published by Free Software Foundation.
// https://www.gnu.org/licenses/gpl-3.0-standalone.html

#pragma once

#include <QDateTime>
#include <QObject>
#include <QString>

class Event : public QObject {
    Q_OBJECT

public:
    explicit Event(QObject* parent = Q_NULLPTR)
        : QObject(parent)
        , name()
        , description()
    {
    }

    Event(QString nameArg, QString descArg, QDateTime beginArg, qint64 durationArg, QObject* parent = Q_NULLPTR)
        : QObject(parent)
        , name(std::move(nameArg))
        , description(std::move(descArg))
        , beginTime(std::move(beginArg))
        , duration(durationArg)
        , repeatFreq(0)
    {
    }

    Q_PROPERTY(QString name
            READ getName
                WRITE setName
                    MEMBER name
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(QString description
            READ getDescription
                WRITE setDescription
                    MEMBER description
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(QDateTime beginTime
            READ getBeginTime
                WRITE setBeginTime
                    MEMBER beginTime
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(qint64 duration
            READ getDuration
                WRITE setDuration
                    MEMBER duration
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(qint64 repeatFreq
            READ getRepeatFreq
                WRITE setRepeatFreq
                    MEMBER repeatFreq
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(bool repeat
            READ getRepeat
                WRITE setRepeat
                    MEMBER repeat
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(bool repeat
            READ getRepeat
                WRITE setRepeat
                    MEMBER repeat
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(bool repeat
            READ getRepeat
                WRITE setRepeat
                    MEMBER repeat
                        SCRIPTABLE true STORED true USER true FINAL)

    Q_PROPERTY(bool notify
            READ getNotify
                WRITE setNotify
                    MEMBER notify
                        SCRIPTABLE true STORED true USER true FINAL)

    QString getName() const;
    void setName(const QString&);

    QString getDescription() const;
    void setDescription(const QString&);

    QDateTime getBeginTime() const;
    void setBeginTime(const QDateTime&);

    qint64 getDuration() const;
    void setDuration(const qint64&);

    qint64 getRepeatFreq() const;
    void setRepeatFreq(const qint64&);

    bool getRepeat() const;
    void setRepeat(const bool&);

    bool getNotify() const;
    void setNotify(const bool&);

private:
    QString name;
    QString description;
    QDateTime beginTime;
    qint64 duration{ 0 };
    bool notify{ false };
    bool repeat{ false };
    qint64 repeatFreq{ 0 };
};

#endif // EVENT_H
