#include "../include/Brain.hpp"

#include <iostream>

Brain::Brain(void) 
{
    std::cout << "A brain has been created " << std::endl;
}

Brain::Brain(Brain const & src) 
{
    *this = src;
    return ;
}

Brain::~Brain() 
{
    std::cout << "A brain has been deleted " << std::endl;
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

