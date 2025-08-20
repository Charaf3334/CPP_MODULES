#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &theOtherObject);
        Animal& operator=(const Animal &theOtherObject);
        virtual ~Animal();
        virtual void makeSound(void) const = 0; // pure virtual functions which makes our class an abstract class
        std::string getType(void) const;
};

#endif