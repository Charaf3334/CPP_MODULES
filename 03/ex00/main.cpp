#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Jack");
    ClapTrap b("Tom");

    a.attack("Tom");      // Jack attacks Tom
    a.takeDamage(5);      // Jack takes damage
    a.beRepaired(3);      // Jack repairs
    a.takeDamage(20);     // Jack takes fatal damage
    a.attack("Tom");      // Jack should NOT attack (0 HP)
    a.beRepaired(10);     // Jack should NOT repair (0 HP)

    return 0;
}
