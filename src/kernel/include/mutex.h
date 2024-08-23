#pragma once
#include <stdatomic.h>

typedef atomic_flag mutex_t;
void MutexLock(atomic_flag* mutex);
void MutexUnlock(atomic_flag* mutex);