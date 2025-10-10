#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        struct iterator
        {
            T* pointer;
        
            iterator();
            iterator(T* pointer);
            T& operator*() const;
            iterator operator++();
            iterator operator++(int);
            iterator operator--();
            iterator operator--(int);
            iterator operator-(int num);
            iterator operator+(int num);
            bool operator==(const iterator &theOtherObject) const;
            bool operator!=(const iterator &theOtherObject) const;
        };
        MutantStack();
        MutantStack(const MutantStack &theOtherObject);
        MutantStack& operator=(const MutantStack &theOtherObject);
        ~MutantStack();
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif