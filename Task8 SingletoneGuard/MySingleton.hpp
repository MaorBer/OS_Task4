#ifndef MYSINGLETON_HPP
#define MYSINGLETON_HPP

#include "Singleton.hpp"
#include <iostream>

class MySingleton : public Singleton {
private:
    MySingleton() {
        std::cout << "MySingleton instance created.\n";
    }

    friend class Singleton;

public:
    void show() const override {
        std::cout << "MySingleton instance is active.\n";
    }
};

#endif // MYSINGLETON_HPP
