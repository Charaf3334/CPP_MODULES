#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat &theOtherObject);
        Cat& operator=(const Cat &theOtherObject);
        ~Cat();
        void makeSound(void) const;
};

#endif