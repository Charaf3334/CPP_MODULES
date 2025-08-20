#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &theOtherObject);
        WrongCat& operator=(const WrongCat &theOtherObject);
        ~WrongCat();
        void makeSound(void) const;
};

#endif