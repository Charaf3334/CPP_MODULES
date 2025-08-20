#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &theOtherObject);
        Cat& operator=(const Cat &theOtherObject);
        ~Cat();
        void makeSound(void) const;
};

#endif