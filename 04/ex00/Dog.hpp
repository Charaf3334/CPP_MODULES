#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &theOtherObject);
        Dog& operator=(const Dog &theOtherObject);
        ~Dog();
        void makeSound(void) const;
};

#endif