#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(const std::string& type);
        std::string& getType();
        void setType(const std::string& newType);
};

#endif