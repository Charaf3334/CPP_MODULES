#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
int easyfind(const T& container, const int target)
{
    typename T::const_iterator iterator = std::find(container.begin(), container.end(), target);
    if (iterator != container.end())
    {
        int i = std::distance(container.begin(), iterator);
        return i;
    }
    else
        throw std::runtime_error("Error: Value not found");
}

#endif