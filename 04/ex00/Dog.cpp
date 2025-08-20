#include "Dog.hpp"

Dog::Dog() {

    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}


Dog::Dog(const Dog &theOtherObject) : Animal(theOtherObject) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &theOtherObject)
{
    if (this != &theOtherObject)
        Animal::operator=(theOtherObject);
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Barking!" << std::endl;
}
