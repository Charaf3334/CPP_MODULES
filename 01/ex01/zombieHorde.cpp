#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    
    Zombie *arr_of_zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
        arr_of_zombies[i].nameZombies(name);
    
    return arr_of_zombies;
}