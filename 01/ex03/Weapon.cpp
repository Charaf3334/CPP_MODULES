#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
    this->type = type;
}

std::string& Weapon::getType(void)
{
    return type;
}

void Weapon::setType(const std::string& typeToSet)
{
    type = typeToSet;
}
