#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    // Animal animal1;

    const int size = 2;

    Animal *animals[size]; // we can have pointers to abstract class that can point to child objects that contain the implementation of the pure base virtual methods

    animals[0] = new Dog();
    animals[1] = new Cat();

    std::cout << "------------------------------------------" << std::endl;
    
    animals[0]->makeSound();
    animals[1]->makeSound();
    
    std::cout << "------------------------------------------" << std::endl;
    
    delete animals[0];
    delete animals[1];

    return 0;
}
