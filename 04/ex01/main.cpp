#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    const int size = 2;

    Animal *animals[size];

    animals[0] = new Dog();
    animals[1] = new Cat();

    delete animals[0];
    delete animals[1];

    return 0;
}
