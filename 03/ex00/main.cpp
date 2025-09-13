#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Jack");

    a.attack("Tom");    
    a.takeDamage(5);     
    a.beRepaired(3);
    a.takeDamage(20);
    a.attack("Tom"); 
    a.beRepaired(10);

    return 0;
}
