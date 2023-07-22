#include "../include/AMateria.hpp"

#include <iostream>

AMateria::AMateria(void) 
{
    std::cout << "constructeur de Materia" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "constructeur de Materia" << std::endl;
}

AMateria::AMateria(AMateria const & src) 
{
    *this = src;
    return ;
}

AMateria::~AMateria() 
{
    std::cout << "Destructeur de Materia" << std::endl;
}

AMateria &    AMateria::operator=( AMateria const & rhs ) 
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (_type);
}

 void AMateria::use (ICharacter & target)
 {
    
 }






