#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SIZE 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *array[SIZE];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &theOtherObject);
        MateriaSource& operator=(const MateriaSource &theOtherObject);
        ~MateriaSource();
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const &type);
};

#endif