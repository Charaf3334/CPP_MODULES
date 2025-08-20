#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap c("clap");
    ScavTrap s("scav");

    c.attack("scav");
    s.attack("clap");

    s.takeDamage(10);

    return 0;
}