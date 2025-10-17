#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <limits.h>
#include "Algos.hpp"

class PmergeMe
{
    private:
        size_t size;
        std::vector<int> V;
        std::deque<int> D;

        size_t countSize(char **sequence);
        void checkInput(char **sequence);
        void validNumber(std::string n);
        void storeAtContainers(char **sequence);
        void printing(const std::string expression) const;
        
    public:
        PmergeMe();
        PmergeMe(char **sequence);
        PmergeMe(const PmergeMe &theOtherObject);
        PmergeMe& operator=(const PmergeMe &theOtherObject);
        ~PmergeMe();
        void sortVector(void);
        void sortDeque(void);
        bool alreadySorted(void) const;
};

#endif