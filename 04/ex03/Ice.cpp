#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &theOtherObject) : AMateria(theOtherObject)
{

}

Ice& Ice::operator=(const Ice &theOtherObject)
{
    (void)theOtherObject;
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice deconstructor" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}