#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <pthread.h>
#include <memory>

// Abstract base Singleton class to ensure controlled instantiation of derived classes.
class Singleton {
public:
    static pthread_mutex_t mutex;  // Declare mutex for synchronizing instance creation.

protected:
    Singleton() {}  // Protected constructor to prevent direct instantiation from outside.

public:
    // Delete copy constructor and assignment operator to enforce a single instance.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    virtual ~Singleton() {}

    // Pure virtual function to make the base class abstract.
    virtual void show() const = 0;

    // Template-based, thread-safe method to retrieve or create the singleton instance.
    template<typename T>
    static std::shared_ptr<T> getInstance() {
        static std::shared_ptr<T> instance = nullptr;

        // Double-checked locking to avoid unnecessary mutex locks once the instance is created.
        if (!instance) {
            pthread_mutex_lock(&mutex);  // Lock to prevent race conditions during instance creation.
            if (!instance) {
                instance = std::shared_ptr<T>(new T());  // Allocate the singleton instance.
            }
            pthread_mutex_unlock(&mutex);  // Unlock after the critical section is finished.
        }

        return instance;
    }
};

#endif // SINGLETON_HPP
