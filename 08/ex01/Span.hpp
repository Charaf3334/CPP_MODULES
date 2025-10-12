#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits.h>

class Span
{
    private:
        std::vector<int> span;
        unsigned int max_size;
        unsigned int tracker;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &theOtherObject);
        Span& operator=(const Span &theOtherObject);
        ~Span();
        void print(void) const;
        void addNumber(int num);
        void addNumberRemastered(void);
        long shortestSpan(void);
        long longestSpan(void);
};

#endif