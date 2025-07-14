#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& w) : name(name), w(w) {

}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}