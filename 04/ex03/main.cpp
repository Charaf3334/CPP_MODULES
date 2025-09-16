#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "---------------------------------------------" << std::endl;

    {
        Character a("Whatever");
        Character b("Whatever2");

        a.equip(new Ice());
        a.unequip(0);

        a.equip(new Cure());
        a.unequip(0);

        b = a;

    }

    MateriaSource a;

    a.learnMateria(new Ice());
    AMateria* p =  a.createMateria("ice");

    delete p;

    return 0;
}