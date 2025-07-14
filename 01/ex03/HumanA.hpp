#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon&     w;
    public:
        HumanA(const std::string& name, Weapon& w);
        void attack();
};

#endif