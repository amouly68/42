#include "../include/Cure.hpp"

#include <iostream>

Cure::Cure(void) 
{
    AMateria::_type = "cure";
    std::cout << "Constructeur de cure" << std::endl;
}

Cure::Cure(Cure const & src) 
{
    *this = src;
    return ;
}

Cure::~Cure() 
{
    std::cout << "Destructeur de cure" << std::endl;
}

Cure &    Cure::operator=( Cure const & rhs ) 
{
    this->_type = rhs._type;
    return (*this);
}

 AMateria* Cure::clone() const 
{
    Cure * ret = new Cure;
    ret->_type = this->_type;
    return (ret);
}

void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target << "'s wounds *" << std::endl;
}

