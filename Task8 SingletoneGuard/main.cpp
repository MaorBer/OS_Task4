#include <iostream>
#include "Singleton.hpp"
#include "MutexGuard.hpp"
#include "MySingleton.hpp"

// Initialize the static mutex
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    // Getting the singleton instance
    // Retrieves or creates an instance of MySingleton using the thread-safe getInstance method from Singleton.
    auto instance = Singleton::getInstance<MySingleton>();
    
    // Call the show method to demonstrate the functionality of the singleton instance.
    instance->show();

    // Using MutexGuard for scoped locking
    {
        // Create a MutexGuard to lock the singleton's mutex.
        // This ensures that the critical section below has exclusive access.
        MutexGuard guard(&Singleton::mutex);
        std::cout << "Mutex is locked within this scope.\n";
        // Critical section can go here (place any code that requires exclusive access here)
    }

    // The MutexGuard automatically unlocks the mutex when it goes out of scope.
    std::cout << "Mutex is unlocked after guard is out of scope.\n";
    
    return 0;  // Return 0 to indicate successful execution of the program.
}
