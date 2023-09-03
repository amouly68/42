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
    (void) rhs;
    return (*this);
}

AForm*        Intern::makeForm(std::string type, std::string target)
{
    
    AForm * form;
    try
    {
        form = AForm::makeForm(type, target);
        std::cout << "Intern creates " << type << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Intern could'nt create Form because"<< e.what() << std::endl;
    }
    
    return form;
}