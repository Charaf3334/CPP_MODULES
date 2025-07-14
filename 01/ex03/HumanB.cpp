#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), w(nullptr) {

}

void HumanB::setWeapon(Weapon& w)
{
    this->w = &w;
}

void HumanB::attack()
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}