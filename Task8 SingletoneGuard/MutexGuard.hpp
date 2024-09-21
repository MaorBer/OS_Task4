#ifndef MUTEXGUARD_HPP
#define MUTEXGUARD_HPP

#include <pthread.h>

class MutexGuard {
private:
    pthread_mutex_t* mtx;

public:
    explicit MutexGuard(pthread_mutex_t* mutex) : mtx(mutex) {
        pthread_mutex_lock(mtx);
    }

    ~MutexGuard() {
        pthread_mutex_unlock(mtx);
    }

    // Deleted copy constructor and assignment operator
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;
};

#endif // MUTEXGUARD_HPP
