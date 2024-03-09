#ifndef VECTOR.H
#define VECTOR.H

#include <iostream>

template <typename T>
class Vector {
private:
    size_t size;
    size_t capacity;
    T* array;

public:
    using value_type = T;
    using size_type = size_t;
    using referance = T&;
    using cons_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;

// Prototypes for ctor and dtor
public:
    Vector();
    Vector(size_t length);
    Vector(size_t length, const T& value);
    Vector(const Vector&)
    const Vector& operator=(const Vector rhv);
    ~Vector();

public:
    void resize(size_t size, const T& val);

private:
    void reAllocate(size_t newCapacity);

//Getters for features
public:
    size_t size();
    size_t capacity();
    T& operator[](size_t index);
    bool empty();
    T& front();
    T& back();

// For modifying content of the array
public:
    void push_back(const T& value);
    void pop_back();
    void insert(size_t index, const T& value);
    void erase(size_t index);
    void clear() noexcept;
};

#include "vector.cpp"
#endif