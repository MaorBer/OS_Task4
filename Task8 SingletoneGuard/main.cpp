#include <iostream>
#include "Singleton.hpp"
#include "MutexGuard.hpp"
#include "MySingleton.hpp"

// Initialize the static mutex
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    // Getting the singleton instance
    auto instance = Singleton::getInstance<MySingleton>();
    instance->show();

    // Using MutexGuard for scoped locking
    {
        MutexGuard guard(&Singleton::mutex);
        std::cout << "Mutex is locked within this scope.\n";
        // Critical section can go here
    }

    std::cout << "Mutex is unlocked after guard is out of scope.\n";
    
    return 0;
}
