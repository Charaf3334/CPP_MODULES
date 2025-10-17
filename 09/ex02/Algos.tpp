#include "Algos.hpp"

template <class T>
Algos<T>::Algos()
{
    
}

template <class T>
Algos<T>::Algos(const Algos &theOtherObject)
{
    static_cast<void>(theOtherObject);
}

template <class T>
Algos<T>& Algos<T>::operator=(const Algos &theOtherObject)
{
    if (this != &theOtherObject)
        static_cast<void>(theOtherObject);
    return *this;
}

template <class T>
Algos<T>::~Algos()
{

}

template <class T>
size_t Algos<T>::binarySearch(const T& container, size_t startAt, size_t endAt, int target)
{
    size_t left = startAt;
    size_t right = endAt;
    size_t mid = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (container[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template <class T>
void Algos<T>::mergeInsertSortingVector(std::vector<int> &container, size_t size)
{
    if (size <= 1)
        return;

    std::vector<int> large_pairs;
    std::vector<int> small_pairs;

    for (size_t i = 0; i + 1 < size; i += 2)
    {
        if (container[i] > container[i + 1]) 
        {
            large_pairs.push_back(container[i]);
            small_pairs.push_back(container[i + 1]);
        } 
        else 
        {
            large_pairs.push_back(container[i + 1]);
            small_pairs.push_back(container[i]);
        }
    }
    if (size % 2 == 1)
        small_pairs.push_back(container[size - 1]);
    
    mergeInsertSortingVector(large_pairs, large_pairs.size());
    
    for (size_t i = 0; i < large_pairs.size(); i++)
        container[i] = large_pairs[i];

    for (size_t i = 0; i < small_pairs.size(); i++)
    {
        size_t indexToInsert = binarySearch(container, 0, large_pairs.size() + i, small_pairs[i]);
        size_t j = large_pairs.size() + i;

        for (; j > indexToInsert; j--)
            container[j] = container[j - 1];

        container[indexToInsert] = small_pairs[i];
    }
}

template <class T>
void Algos<T>::mergeInsertSortingDeque(std::deque<int> &container, size_t size)
{
    if (size <= 1)
        return;
    
    std::deque<int> large_pairs;
    std::deque<int> small_pairs;

    for (size_t i = 0; i + 1 < size; i += 2)
    {
        if (container[i] > container[i + 1]) 
        {
            large_pairs.push_back(container[i]);
            small_pairs.push_back(container[i + 1]);
        }
        else 
        {
            large_pairs.push_back(container[i + 1]);
            small_pairs.push_back(container[i]);
        }
    }
    if (size % 2 == 1)
        small_pairs.push_back(container[size - 1]);

    mergeInsertSortingDeque(large_pairs, large_pairs.size());

    for (size_t i = 0; i < large_pairs.size(); i++)
        container[i] = large_pairs[i];

    for (size_t i = 0; i < small_pairs.size(); i++)
    {
        size_t indexToInsert = binarySearch(container, 0, large_pairs.size() + i, small_pairs[i]);
        size_t j = large_pairs.size() + i;

        for (; j > indexToInsert; j--)
            container[j] = container[j - 1];

        container[indexToInsert] = small_pairs[i];
    }
}