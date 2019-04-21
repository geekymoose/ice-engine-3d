#pragma once


/**
 * Object that extends Uncopyable can't be copied anymore.
 *
 * \remark
 * Example: class A : private Uncopyable<A> { ... }
 */
template<class T>
class Uncopyable {
    public:
        Uncopyable() = default;
        virtual ~Uncopyable() = default;

    private:
        Uncopyable(Uncopyable<T> const& other) = delete;
        Uncopyable<T>& operator=(Uncopyable<T> const& other) = delete;
};


