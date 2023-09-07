#include "../include/Array.hpp"

#include <iostream>

Array::Array(void) 
{
    
}

Array::Array(unsigned int n)
{
    _arr = new [n] T;
}


Array::Array(Array const & src) 
{
    *this = src;
    return ;
}

Array::~Array() 
{
    // TODO: Implémenter le destructeur
}

Array &    Array::operator=( Array const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

