#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <pthread.h>
#include <memory>

class Singleton {
public:  // Change to public
    static pthread_mutex_t mutex;  // Mutex for thread safety

protected:
    Singleton() {}  // Protected constructor

public:
    // Deleted copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    virtual ~Singleton() {}

    // Pure virtual function
    virtual void show() const = 0;

    // Thread-safe method to get the singleton instance
    template<typename T>
    static std::shared_ptr<T> getInstance() {
        pthread_mutex_lock(&mutex);
        static std::shared_ptr<T> instance(new T());
        pthread_mutex_unlock(&mutex);
        return instance;
    }
};

#endif // SINGLETON_HPP
