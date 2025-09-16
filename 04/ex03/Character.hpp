#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define SIZE 4

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[SIZE];
        AMateria *saving[SIZE];
    public:
        Character();
        Character(std::string name);
        Character(const Character &theOtherObject);
        Character& operator=(const Character &theOtherObject);
        ~Character();
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif