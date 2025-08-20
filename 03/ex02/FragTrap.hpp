#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &theOtherObject);
        FragTrap& operator=(const FragTrap &theOtherObject);
        ~FragTrap();
        void highFivesGuys(void) const;
};

#endif