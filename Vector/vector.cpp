#include "vector.h"

// Setting ctor and dtor
template <typename T>
Vector<T>::Vector() : size(0), capacity(5), array(nullptr) {} // default ctor

template <typename T>
Vector<T>::Vector(size_t length){ // Constructor with a size initialisation
    if(length < 0) throw 1;
    size = length;
    capasity = size * 2;
    arr = new T[capacity];
}

template <typename T>
Vector<T>::Vector(size_t length, const T& value) // Constructor with a set of parameters
    : size(length), 
    capacity(length * 2) { 
    if(size < 0) return;
    arr = new T[capacity];
    for(int i = 0; i < size; ++i){
    arr[i] = value;
    }
}
template <typename T>
Vector<T>::Vector(const Vector& rhv) 
    : size{rhv.size}
    , capacity{rhv.capacity}
    , arr{new T[rhv.capacity]} {
        for(int i = 0; i < size; ++i){
            array[i] = rhv.array[i];
        }
    } 
template <typename T>
const Vector& 
Vector<T>::operator=(const Vector& rhv){
    if(this != &rhv){
        clear();
        size = rhv.size;
        capacity = rhv.capacity;
        array = new int[capacity];
        for(int i = 0; i < size; ++i){
            array[i] = rhv.array[i];
        }
    }
    return *this;
}
// Destructor
template <typename T>
Vector<T>::~Vector(){
    clear();
}

template <typename T>
size_t Vector<T>::size(){
    return size;
}

template <typename T>
size_t Vector<T>::capacity() {
    return capacity;
}

template <typename T>
T& Vector<T>::operator[](size_t index){
    if(index > size) throw 1;
    return array[index];
}

// For modifying content of the array
template <typename T>
void Vector<T>::push_back(const T& value){
    if(size >= capacity) reAllocate(capacity * 2);
    array[size] = value;
    size++;
}
template <typename T>
void Vector<T>::pop_back(){
    if(size == 0) return;
    size--;
}
template <typename T>
void Vector<T>::insert(size_t index, const T& value){
        if(size >= capacity) reAllocate();
        ++size;

        for(int i = 0; i < size; ++i){
            if(i == index) {
                T temp = array[index];
                array[index] = value;
                value = temp;
            }
        }
        for(int i = index+1; i < size; ++i){
            T copy = array[i];
            array[i] = value;
            value = copy;
        }
}
template <typename T>
void Vector<T>::erase(size_t index){
        if(index >= length && index < 0){
            std::cout << "Out of range.\n";
        }

        for(int i = index; i < length; ++i){
            arr[i] = arr[i+1];
        }
        --length;
    }

template <typename T>
void Vector<T>::clear() noexcept {
    delete[] array;
    array = nullptr;
    size = 0;
    capacity = 0;
}
template <typename T>
bool Vector<T>::empty(){
        if(size == 0) return 1;
        return 0;
    }
template <typename T>
T& Vector<T>::front(){
        if(size == 0) throw 1;
        return *array;
    }

template <typename T>
T& Vector<T>::back(){
        if(size == 0) throw 1;
        return array[size - 1];
    }

template <typename T>
void Vector<T>::reAllocate(size_t newCapacity){
    T* newArray = new T[newCapacity];

    if(newCapacity < size) size = newCapacity;

    for(size_t i = 0; i < size; ++i){
        newArray = array[i];
    }
    delete[] array;
    array = newArray;
    newArray = nullptr;
    capacity = newCapacity;
}
