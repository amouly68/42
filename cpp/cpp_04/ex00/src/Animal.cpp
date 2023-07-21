#include "../include/Animal.hpp"

#include <iostream>

Animal::Animal(void) 
{
    // TODO: Implémenter le constructeur
}

Animal::Animal(Animal const & src) 
{
    *this = src;
    return ;
}

Animal::~Animal() 
{
    // TODO: Implémenter le destructeur
}

Animal &    Animal::operator=( Animal const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

