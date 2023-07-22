#include "../include/Character.hpp"

#include <iostream>

Character::Character(void) : _Name("No_Name")
{
    std::cout << "Character constructor" << std::endl;
    int i = 0;
    while (i < 4)
    {
        this->_Inventaire[i] = NULL;
        i+;
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
        i+;
    }
    return;
}


Character::Character(Character const & src) 
{
    this->_Name = src._Name;

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
    // TODO: Implémenter l'operateur d'assignemet
}

std::string const & Character::getName() const
{
    return (this->_Name)
}

void Character::equip(AMateria * m)
{
    int i = 0;
    while(i < 4)
    {
        if (this->_Inventaire[i] == NULL)
        {
            this->_Inventaire[i] = m;
            break;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Iventaire full please Unequip !!" << std::endl;
    return; 
}

void Character::unequip(int idx)
{
    if (idx > 0 || idx < 3)
        this->_Inventaire[idx] = NULL;
    else
        std::cout << "PLease use an index between 0 and 3." << std::endl;
    return; 
}

void Character::use(int idx, ICharacter & target)
{
    this->_Inventaire[idx]->use(target);
    return;
}