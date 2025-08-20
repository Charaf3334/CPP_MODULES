#include "WrongCat.hpp"

WrongCat::WrongCat() {

    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &theOtherObject) : WrongAnimal(theOtherObject) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &theOtherObject)
{
    if (this != &theOtherObject)
        WrongAnimal::operator=(theOtherObject);
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
