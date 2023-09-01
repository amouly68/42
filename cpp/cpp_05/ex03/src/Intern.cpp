#include "../include/Intern.hpp"

#include <iostream>

Intern::Intern(void) 
{
    std::cout << "An Intern has been created" << std::endl;
}

Intern::Intern(Intern const & src) 
{
    *this = src;
    return ;
}

Intern::~Intern() 
{
    std::cout << "An Intern has been destroyed" << std::endl;
}

Intern &    Intern::operator=( Intern const & rhs ) 
{

    return (*this);
}

AForm*        Intern::makeForm(std::string form, std::string target)
{
    
}