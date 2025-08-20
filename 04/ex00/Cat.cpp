#include "Cat.hpp"

Cat::Cat() {

    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(const Cat &theOtherObject) : Animal(theOtherObject) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &theOtherObject)
{
    if (this != &theOtherObject)
        Animal::operator=(theOtherObject);
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
