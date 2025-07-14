#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void    nameZombies(std::string n);
        void    announce();
};

Zombie  *zombieHorde(int N, std::string name);

#endif