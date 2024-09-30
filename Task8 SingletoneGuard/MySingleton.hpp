#ifndef MYSINGLETON_HPP
#define MYSINGLETON_HPP

#include "Singleton.hpp"
#include <iostream>

// Derived Singleton class with specific functionality.
class MySingleton : public Singleton {
private:
    // Private constructor ensures that instances can only be created via the Singleton base class.
    MySingleton() {
        std::cout << "MySingleton instance created.\n";
    }

    friend class Singleton;  // Allow Singleton class to call the private constructor.

public:
    // Implementation of the pure virtual function from the Singleton base class.
    void show() const override {
        std::cout << "MySingleton instance is active.\n";
    }
};

#endif // MYSINGLETON_HPP
