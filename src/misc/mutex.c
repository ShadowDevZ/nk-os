#include <stdatomic.h>
#include "io.h"
#include "mutex.h"

void MutexLock(mutex_t* mutex) {
    while (atomic_flag_test_and_set(mutex)){
        x64_pause();
    }
}
void MutexUnlock(mutex_t* mutex) {
    atomic_flag_clear(mutex);
}