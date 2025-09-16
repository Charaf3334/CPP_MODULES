#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string const type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &theOtherObject);
        AMateria& operator=(const AMateria &theOtherObject);
        virtual ~AMateria();
        std::string const& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif