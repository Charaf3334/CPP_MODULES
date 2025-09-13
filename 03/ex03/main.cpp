#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d1("Diamond");

    d1.whoAmI();
    d1.attack("Enemy");
    d1.takeDamage(10);
    d1.beRepaired(5);
    d1.highFivesGuys();
    d1.guardGate();

    return 0;
}
