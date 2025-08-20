#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain default constuctor called" << std::endl;
}

Brain::Brain(const Brain &theOtherObject)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = theOtherObject.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &theOtherObject)
{
    if (this != &theOtherObject)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = theOtherObject.ideas[i];
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain destructor called" << std::endl;
}