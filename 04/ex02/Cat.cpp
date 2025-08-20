#include "Cat.hpp"

Cat::Cat() {

    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(const Cat &theOtherObject) : Animal(theOtherObject) 
{
    this->brain = new Brain(*theOtherObject.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &theOtherObject)
{
    if (this != &theOtherObject) {
        Animal::operator=(theOtherObject);
        delete this->brain;
        this->brain = new Brain(*theOtherObject.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
