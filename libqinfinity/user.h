#ifndef QINFINITY_USER_H
#define QINFINITY_USER_H

#include "qgobject.h"

#include <libinfinity/common/inf-user.h>

#include <QPointer>

namespace QInfinity
{

class User
    : public QGObject
{

    public:
        enum Status
        {
            Active,
            Inactive,
            Unavailable
        };

        static QPointer<User> wrap( InfUser *infUser,
            QObject *parent = 0,
            bool own_gobject = false );
        static Status convertStatus( InfUserStatus status );
        static InfUserStatus convertStatus( Status status );

        unsigned int id();
        QString name();
        Status status();

    protected:

        User( InfUser *infUser,
           QObject *parent = 0,
           bool own_gobject = false );

};

}

#endif

