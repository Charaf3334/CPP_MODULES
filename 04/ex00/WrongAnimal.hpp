#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &theOtherObject);
        WrongAnimal& operator=(const WrongAnimal &theOtherObject);
        ~WrongAnimal();
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif