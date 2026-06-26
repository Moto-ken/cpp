
#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) {
    this->data = new T[other._size];
    this->_size = other._size;
    for (unsigned int i = 0; i < _size; i++) this->data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    T* newData = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++) newData[i] = other.data[i];
    delete[] this->data;
    this->data = newData;
    this->_size = other._size;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) throw std::out_of_range("out of range");
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) throw std::out_of_range("out of range");
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
