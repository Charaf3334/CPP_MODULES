#include "Zombie.hpp"

int main(void)
{
    Zombie *z1 = newZombie("Im in Heap");
    z1->announce();
    delete z1;

    randomChump("Im in Stack");

    return (0);
}