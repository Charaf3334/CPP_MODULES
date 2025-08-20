#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &theOtherObject);
        ScavTrap& operator=(const ScavTrap &theOtherObject);
        ~ScavTrap();
        void guardGate() const;
        void attack(const std::string &target);
};

#endif