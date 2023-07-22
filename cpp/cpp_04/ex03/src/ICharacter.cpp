#include "../include/ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter(void) 
{
    // TODO: Implémenter le constructeur
}

ICharacter::ICharacter(ICharacter const & src) 
{
    *this = src;
    return ;
}

ICharacter::~ICharacter() 
{
    // TODO: Implémenter le destructeur
}

ICharacter &    ICharacter::operator=( ICharacter const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

