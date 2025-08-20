#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Unknown";
    std::cout << "Animal default constructor called" << std::endl;
}


Animal::Animal(const Animal &theOtherObject)
{
    this->type = theOtherObject.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &theOtherObject)
{
    if (this != &theOtherObject)
        this->type = theOtherObject.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}


std::string Animal::getType(void) const
{
    return this->type;
}