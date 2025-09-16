#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &theOtherObject) : AMateria(theOtherObject)
{

}

Cure& Cure::operator=(const Cure &theOtherObject)
{
    (void)theOtherObject;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure deconstructor" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}