#include "../include/Character.hpp"

#include <iostream>

Character::Character(void) : _Name("No_Name")
{
    std::cout << "Character constructor" << std::endl;
    int i = 0;
    while (i < 4)
    {
        this->_Inventaire[i] = NULL;
        i++;
    }
    return;
}

Character::Character (std::string name) : _Name(name)
{
    std::cout << "Character constructor" << std::endl;
    int i = 0;
    while (i < 4)
    {
        this->_Inventaire[i] = NULL;
        i++;
    }
    return;
}


Character::Character(Character const & src) 
{
    this->_Name = src._Name;
    int i = 0;
    while (i < 4)
    {
        if (src._Inventaire[i] != NULL)
            this->_Inventaire[i] = src._Inventaire[i]->clone();
        else
            this->_Inventaire[i] = NULL;
        i++;
    }
    return ;
}

Character::~Character() 
{
    std::cout << "Character destructor" << std::endl;
    int i = 0;
    while (i < 4)
    {
        if (this->_Inventaire[i])
            delete this->_Inventaire[i];
        i++;    
    }
}


Character &    Character::operator=( Character const & rhs ) 
{
    this->_Name = rhs._Name;
    this->~Character();
    int i = 0;
    while (i < 4)
    {
        if (rhs._Inventaire[i] != NULL)
            this->_Inventaire[i] = rhs._Inventaire[i]->clone();
        else
            this->_Inventaire[i] = NULL;
        i++;
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->_Name);
}

void Character::equip(AMateria* m)
{
    int i = 0;
    if (m == NULL)
    {
        std::cout << "You try to equip " << this->getName() << " with nothing !!!" << std::endl;
        return;
    }
    while(i < 4)
    {
        if (this->_Inventaire[i] == NULL)
        {
            this->_Inventaire[i] = m;
            std::cout << this->getName() << " is equipped with " <<  m->getType() << " at spot " << i << " !" << std::endl; 
            return;
        }
        i++;
    }
    std::cout << "Iventaire full please Unequip !!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        this->_Inventaire[idx] = NULL;
        std::cout << "Spot " << idx << " is unequipped !" << std::endl;
    }
    else
        std::cout << "PLease use an index between 0 and 3." << std::endl;
}

void Character::use(int idx, ICharacter & target)
{
    if (idx < 0 || idx > 3)
        std::cout << "ONLY 4 SPOTS : 0, 1 , 2, 3" << std::endl;
    else if (this->_Inventaire[idx] == NULL)
        std::cout << "PAS DE MATERIA A CET EMPLACEMENT" << std::endl;
    else
        this->_Inventaire[idx]->use(target);
}