#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void multiply_by_2(T &x)
{
    x = x * 2;
}

template<typename T>
void divide_by_2(T &x)
{
    x = x / 2;
}

template<typename T>
void iter(T *arr, const int length, void (*callback)(T&))
{
    for (int i = 0; i < length; i++)
        callback(arr[i]);
}

template<typename T>
void print_styled(const T& x)
{
    std::cout << "<< " << x << " >>" << std::endl;
}

template<typename T>
void iter(const T *arr, const int length, void (*callback)(const T&))
{
    for (int i = 0; i < length; i++)
        callback(arr[i]);
}

#endif