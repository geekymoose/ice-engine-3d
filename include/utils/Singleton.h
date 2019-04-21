#pragma once

#include "Uncopyable.h"


/**
 * Defines a singleton object.
 */
template<class T>
class Singleton : virtual private Uncopyable<Singleton<T>> {
    private:
        friend T;

    private:
        Singleton() = default;
        virtual ~Singleton() = default;

    public:
        static T& getInstance() {
            static T m;
            return m;
        }
};


