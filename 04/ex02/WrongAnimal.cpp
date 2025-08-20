#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Unknown";
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &theOtherObject)
{
    this->type = theOtherObject.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &theOtherObject)
{
    if (this != &theOtherObject)
        this->type = theOtherObject.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal general sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}