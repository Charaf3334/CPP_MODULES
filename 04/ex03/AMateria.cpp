#include "AMateria.hpp"

AMateria::AMateria() : type("unknown")
{

}

AMateria::AMateria(std::string const &type) : type(type)
{

}

AMateria::AMateria(const AMateria &theOtherObject) : type(theOtherObject.type)
{

}

AMateria& AMateria::operator=(const AMateria &theOtherObject)
{
    (void)theOtherObject;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria deconstructor" << std::endl;
}

std::string const& AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Amateria default use function" << std::endl;
}