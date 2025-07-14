#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
    private:
        std::string name;
        Weapon *w;
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& w);
        void attack();
};

#endif