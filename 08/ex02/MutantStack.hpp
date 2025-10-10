#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        struct Iterator
        {
            T* iterator;
        };
        T* begin()
        {
            return &(*this->c.begin());
        }
        T* end()
        {
            return &(*this->c.end());
        }
};

#endif