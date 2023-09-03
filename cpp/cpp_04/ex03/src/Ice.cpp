#include "../include/Ice.hpp"

#include <iostream>

Ice::Ice(void) 
{
   AMateria::_type = "ice";
    std::cout << "Constructeur d'ice" << std::endl;
}

Ice::Ice(Ice const & src) 
{
    *this = src;
    return ;
}

Ice::~Ice() 
{
      std::cout << "Destructeur d'ice" << std::endl;
}

Ice &    Ice::operator=( Ice const & rhs ) 
{
    this->_type = rhs.getType();
    return (*this);
}

 AMateria* Ice::clone() const 
{
    Ice * ret = new Ice;
    ret->_type = this->_type;
    return (ret);
}

 void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName()  << " *" << std::endl;
}
