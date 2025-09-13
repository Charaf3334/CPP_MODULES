#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap c("scav2");

    c.attack("clap");
    c.takeDamage(20);
    c.guardGate();

    return 0;
}