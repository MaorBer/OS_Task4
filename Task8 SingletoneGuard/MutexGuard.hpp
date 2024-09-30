#ifndef MUTEXGUARD_HPP
#define MUTEXGUARD_HPP

#include <pthread.h>

// A Guard class following the RAII (Resource Acquisition Is Initialization) idiom for mutex locking.
class MutexGuard {
private:
    pthread_mutex_t* mtx;  // Pointer to the mutex to be managed.

public:
    // Constructor locks the mutex when the guard object is created.
    explicit MutexGuard(pthread_mutex_t* mutex) : mtx(mutex) {
        pthread_mutex_lock(mtx);
    }

    // Destructor unlocks the mutex when the guard object goes out of scope.
    ~MutexGuard() {
        pthread_mutex_unlock(mtx);
    }

    // Deleting the copy constructor and assignment operator to prevent copying of the guard.
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;
};

#endif // MUTEXGUARD_HPP
