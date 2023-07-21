#include "../include/Dog.hpp"

#include <iostream>

Dog::Dog(void) 
{
    // TODO: Implémenter le constructeur
}

Dog::Dog(Dog const & src) 
{
    *this = src;
    return ;
}

Dog::~Dog() 
{
    // TODO: Implémenter le destructeur
}

Dog &    Dog::operator=( Dog const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

