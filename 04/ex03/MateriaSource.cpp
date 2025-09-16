#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < SIZE; i++)
        this->array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &theOtherObject)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (theOtherObject.array[i])
            this->array[i] = theOtherObject.array[i]->clone();
        else
            this->array[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &theOtherObject)
{
    if (this != &theOtherObject)
    {
        for (int i = 0; i < SIZE; i++)
        {
            delete this->array[i];
            if (theOtherObject.array[i])
                this->array[i] = theOtherObject.array[i]->clone();
            else
                this->array[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < SIZE; i++)
        delete this->array[i];
    std::cout << "MateriaSource deconstructor" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < SIZE; i++)
    {
        if (!this->array[i])
        {
            this->array[i] = materia;
            std::cout << "Materia " << materia->getType() << " learning in index " << i << std::endl;
            return;
        }
    }
    std::cerr << "The learning array is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (this->array[i] && this->array[i]->getType() == type)
        {
            std::cout << "Creating materia of type " << type << std::endl;
            return this->array[i]->clone();
        }
    }
    if (type == "ice" || type == "cure")
        std::cerr << "MateriaSource array has no type " << type << " at the moment" << std::endl;
    else
        std::cerr << "No materia of type " << type << " is there to create" << std::endl;
    return NULL;
}