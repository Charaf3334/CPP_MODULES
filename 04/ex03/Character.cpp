#include "Character.hpp"

Character::Character()
{
    this->name = "unnamed";
    for (int i = 0; i < SIZE; i++) {
        this->inventory[i] = NULL;
        this->saving[i] = NULL;
    }
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < SIZE; i++) {
        this->inventory[i] = NULL;
        this->saving[i] = NULL;
    }
}

Character::Character(const Character &theOtherObject)
{
    this->name = theOtherObject.name;
    for (int i = 0; i < SIZE; i++)
    {
        if (theOtherObject.inventory[i])
            this->inventory[i] = theOtherObject.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        if (theOtherObject.saving[i])
            this->saving[i] = theOtherObject.saving[i]->clone();
        else
            this->saving[i] = NULL;
    }
}

Character& Character::operator=(const Character &theOtherObject)
{
    this->name = theOtherObject.name;
    if (this != &theOtherObject)
    {
        for (int i = 0; i < SIZE; i++)
        {
            delete inventory[i];
            if (theOtherObject.inventory[i])
                this->inventory[i] = theOtherObject.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
            delete saving[i];
            if (theOtherObject.saving[i])
                this->saving[i] = theOtherObject.saving[i]->clone();
            else
                this->saving[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < SIZE; i++)
    {
        delete this->inventory[i];
        this->inventory[i] = NULL;
        delete this->saving[i];
        this->saving[i] = NULL;
    }
    std::cout << "Character deconstructor" << std::endl;
}

std::string const& Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while (i < SIZE && this->inventory[i])
        i++;
    if (i > 3)
    {
        std::cerr << "The inventory is full, can't equip materia" << std::endl;
        delete m;
        return;
    }
    this->inventory[i] = m;
    std::cout << "Character " << this->name << " equipped materia " << m->getType() << " in slot " << i << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= SIZE)
    {
        std::cerr << "The index " << idx << " doesn't exist bro" << std::endl;
        return;
    }
    if (!this->inventory[idx])
    {
        std::cerr << "Can't unequip something that hasn't been equipped" << std::endl;
        return;
    }
    if (this->saving[idx])
    {
        delete this->saving[idx];
        this->saving[idx] = NULL;
    }
    this->saving[idx] = this->inventory[idx];
    this->inventory[idx] = NULL;
    std::cout << "Character " << this->name << " unequipped the materia in slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= SIZE)
    {
        std::cerr << "The index " << idx << " doesn't exist bro" << std::endl;
        return;
    }
    if (!this->inventory[idx])
    {
        std::cerr << "Can't use inventory at index " << idx << std::endl;
        return;
    }
    this->inventory[idx]->use(target);
}