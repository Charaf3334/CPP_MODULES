#ifndef ALGOS_HPP
#define ALGOS_HPP

#include <iostream>

template <class T>
class Algos
{
    private:
        Algos();
        Algos(const Algos &theOtherObject);
        Algos& operator=(const Algos &theOtherObject);
        static size_t binarySearch(const T& container, size_t startAt, size_t endAt, int target);
    public:
        ~Algos();
        static void mergeInsertSortingVector(std::vector<int>& container, size_t end);
        static void mergeInsertSortingDeque(std::deque<int>& container, size_t end);
};

#include "Algos.tpp"

#endif