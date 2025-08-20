#include "Dog.hpp"

Dog::Dog() {

    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}


Dog::Dog(const Dog &theOtherObject) : Animal(theOtherObject) {
    this->brain = new Brain(*theOtherObject.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &theOtherObject)
{
    if (this != &theOtherObject) {
        Animal::operator=(theOtherObject);
        delete brain;
        this->brain = new Brain(*theOtherObject.brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Barking!" << std::endl;
}
