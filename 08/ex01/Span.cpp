#include "Span.hpp"

Span::Span()
{
    throw std::runtime_error("Error: you need to enter N as size of this span.");
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
    if (this->tracker == this->max_size)
        throw std::runtime_error("Error: span is already full.");
    this->span.push_back(num);
    this->tracker++;
}

// tansali lik hh
void Span::addNumberRemastered(void)
{
    srand(time(NULL));
    if (this->tracker == this->max_size)
        throw std::runtime_error("Error: span is already full.");
    std::vector<int>::iterator it;
    std::cout << "here\n";
    for (it = this->span.begin(); it != this->span.end(); ++it)
    {
        int num = rand() % 100 + 1;
        this->span.push_back(num);
        this->tracker++;
    }
}