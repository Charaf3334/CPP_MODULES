#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
    this->name = _name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &theOtherObject)
{
    this->name = theOtherObject.name;
    this->hitPoints = theOtherObject.hitPoints;
    this->energyPoints = theOtherObject.energyPoints;
    this->attackDamage = theOtherObject.attackDamage;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &theOtherObject)
{
    if (this != &theOtherObject)
    {
        this->name = theOtherObject.name;
        this->hitPoints = theOtherObject.hitPoints;
        this->energyPoints = theOtherObject.energyPoints;
        this->attackDamage = theOtherObject.attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no hit points left!" << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no hit points left to take damage!" << std::endl;
        return;
    }
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount
              << " damage and now has " << this->hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no hit points left!" << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
        return;
    }
    this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
              << " and now has " << this->hitPoints << " hit points!" << std::endl;
}
