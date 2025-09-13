#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    this->name = "unnamed";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name")
{
    this->name = _name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &theOtherObject)
    : ClapTrap(theOtherObject), FragTrap(theOtherObject), ScavTrap(theOtherObject)
{
    this->name = theOtherObject.name;
    this->hitPoints = theOtherObject.hitPoints;
    this->energyPoints = theOtherObject.energyPoints;
    this->attackDamage = theOtherObject.attackDamage;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &theOtherObject)
{
    if (this != &theOtherObject)
    {
        ClapTrap::operator=(theOtherObject);
        this->name = theOtherObject.name;
        this->hitPoints = theOtherObject.hitPoints;
        this->energyPoints = theOtherObject.energyPoints;
        this->attackDamage = theOtherObject.attackDamage;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << this->ClapTrap::name << std::endl;
}