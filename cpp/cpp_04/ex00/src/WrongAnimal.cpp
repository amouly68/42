#include "../include/WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) : type("Default")
{
    std::cout << "One WRONG animal has been created of type " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) 
{
    std::cout << "One WRONG animal has been created of type " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) 
{
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "The WRONG animal of type " << this->type << " has been deleted!" << std::endl;
}

std::string   WrongAnimal::getType ()  const 
{
    return (this->type);
}

WrongAnimal &    WrongAnimal::operator=( WrongAnimal const & rhs ) 
{
    if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void   WrongAnimal::makeSound() const
{
    std::cout << "Sound of WRONG ANIMAL" << std::endl;
}