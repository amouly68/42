#include "../include/Brain.hpp"

#include <iostream>

Brain::Brain(void) 
{
    // TODO: Implémenter le constructeur
}

Brain::Brain(Brain const & src) 
{
    *this = src;
    return ;
}

Brain::~Brain() 
{
    // TODO: Implémenter le destructeur
}

Brain &    Brain::operator=( Brain const & rhs ) 
{
    int i = 0;
    if(this != &rhs)
    {
        while (i < 100)
        this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

