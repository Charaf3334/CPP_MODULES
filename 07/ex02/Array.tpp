#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
    this->array = NULL;
    this->_size = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
    this->array = new T[n];
    this->_size = n;
    for (size_t i = 0; i < n; i++)
        this->array[i] = T();
}

template <class T>
Array<T>::Array(const Array &theOtherObject)
{
    this->array = new T[theOtherObject._size];
    this->_size = theOtherObject._size;
    for (size_t i = 0; i < this->_size; i++)
        this->array[i] = theOtherObject.array[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& theOtherObject)
{
    if (this != &theOtherObject)
    {
        delete[] this->array;
        this->array = new T[theOtherObject._size];
        this->_size = theOtherObject._size;
        for (size_t i = 0; i < this->_size; i++)
            this->array[i] = theOtherObject.array[i];
    }
    return *this;
}

template <class T>
Array<T>::~Array()
{
    delete[] this->array;
    this->array = NULL;
    this->_size = 0;
}

template <class T>
T& Array<T>::operator[](int index)
{
    if (index < 0)
        throw std::out_of_range("index is negative");
    if (index >= static_cast<int>(this->_size))
        throw std::out_of_range("index is out from range of the array");
    return this->array[index];
}

template <class T>
size_t Array<T>::size(void) const
{
    return this->_size;
}

#endif