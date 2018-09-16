/*
 * File:    locker_nest.h
 */

#include "locker.h"

#ifndef LOCKER_NEST_H
#define LOCKER_NEST_H

DECLS_BEGIN

typedef int (*TaskSelfFunc)(void);
Locker* locker_nest_create(Locker* real_locker, TaskSelfFunc task_self);

DECLS_END

#endif/*LOCKER_NEST_H*/

