#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &theOtherObject);
        Cure& operator=(const Cure &theOtherObject);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif