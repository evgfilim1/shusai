#include <QSharedMemory>
#include <QString>
#pragma once

/// @brief Encapsulates unique instance checking algorithm using the interprocess shared memory.
class OneInstanceCheck
{
    QSharedMemory m_shmem;
public:
    /// @brief Attempts to create the shared memory region with the checkid as the key.
    OneInstanceCheck(const QString& checkId)
        : m_shmem(checkId)
    {
        // (from https://github.com/itay-grudev/SingleApplication/blob/master/singleapplication.cpp)
        // Guarantee thread safe behaviour with a shared memory block. Also by
        // explicitly attaching it and then deleting it we make sure that the
        // memory is deleted even if the process had crashed on Unix.
     #ifdef Q_OS_UNIX
        memory.attach(ReadOnly);
        memory.~QSharedMemory();
        memory.QSharedMemory(checkId);
     #endif

    }

    /// @brief Checks that the instance of the application is unique.
    bool unique()
    {
        // if we can't attach to memory, then we are unique. And we try to create it.
        if (!m_shmem.attach()) {
            m_shmem.create(1);
            return true;
        } else {
            return false;
        }
    }
};
