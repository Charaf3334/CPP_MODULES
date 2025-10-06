#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
    private:
        T* array;
        size_t _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &theOtherObject);
        Array& operator=(const Array &theOtherObject);
        ~Array();
        T& operator[](int index);
        size_t size(void) const;
};

#include "Array.tpp"

#endif