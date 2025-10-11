#include "Span.hpp"

Span::Span()
{
    this->span.reserve(0);
    this->max_size = 0;
    this->tracker = 0;
}

Span::Span(unsigned int N)
{
    this->span.reserve(N); // note: dont work with resize hh 
    this->max_size = N;
    this->tracker = 0;
}

Span::Span(const Span &theOtherObject)
{
    this->span = theOtherObject.span;
    this->max_size = theOtherObject.max_size;
    this->tracker = theOtherObject.tracker;
}

Span& Span::operator=(const Span &theOtherObject)
{
    if (this != &theOtherObject)
    {
        this->span = theOtherObject.span;
        this->max_size = theOtherObject.max_size;
        this->tracker = theOtherObject.tracker;
    }
    return *this;
}

Span::~Span()
{

}

void Span::print(void) const
{
    for (size_t i = 0; i < this->span.size(); i++)
        std::cout << span[i] << std::endl;
}

void Span::addNumber(int num)
{
    if (!this->tracker && !this->max_size)
        throw std::runtime_error("Error: span is of size 0.");
    if (this->tracker == this->max_size)
        throw std::runtime_error("Error: span is already full.");
    this->span.push_back(num);
    this->tracker++;
}

void Span::addNumberRemastered(void)
{
    if (!this->tracker && !this->max_size)
        throw std::runtime_error("Error: span is of size 0.");
    if (this->tracker == this->max_size)
        throw std::runtime_error("Error: span is already full.");
    while (this->tracker < this->max_size)
    {
        int num = rand() % 101;
        this->span.push_back(num);
        this->tracker++;
    }
}

int Span::shortestSpan(void)
{
    size_t size = this->span.size();
    if (!size)
        throw std::runtime_error("Error: no elements are in the span.");
    if (size == 1)
        throw std::runtime_error("Error: span has only one element.");
    
    std::sort(this->span.begin(), this->span.end());

    std::vector<int>::iterator iterator = this->span.end() - 1;

    int dist = INT_MAX;
    while (iterator != this->span.begin())
    {
        int tmp = *iterator - *(iterator - 1);
        if (tmp < dist)
            dist = tmp;
        iterator--;
    }
    return dist;
}

int Span::longestSpan(void)
{
    size_t size = this->span.size();
    if (!size)
        throw std::runtime_error("Error: no elements are in the span.");
    if (size == 1)
        throw std::runtime_error("Error: span has only one element.");
    
    std::vector<int>::iterator min = std::min_element(this->span.begin(), this->span.end());
    std::vector<int>::iterator max = std::max_element(this->span.begin(), this->span.end());

    int dist = *max - *min;
    
    return dist;
}