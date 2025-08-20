#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &theOtherObject) : ClapTrap(theOtherObject)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &theOtherObject)
{
    if (this != &theOtherObject)
        ClapTrap::operator=(theOtherObject);
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->name << " is now in gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " has no hit points left!" << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " has no energy points left!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}