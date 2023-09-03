#include "../include/AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal(void) : type("Default") 
{
    std::cout << "One ANIMAL has been created of type " << this->type << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) 
{
    std::cout << "One ANIMAL has been created of type " << this->type << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) 
{
    *this = src;
    return ;
}

AAnimal::~AAnimal() 
{
    std::cout << "The ANIMAL of type " << this->type << " has been deleted!" << std::endl;
}

std::string   AAnimal::getType ()  const 
{
    return (this->type);
}

AAnimal &    AAnimal::operator=( AAnimal const & rhs ) 
{
    if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

