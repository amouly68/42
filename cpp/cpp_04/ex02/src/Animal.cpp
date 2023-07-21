#include "../include/Animal.hpp"

#include <iostream>

Animal::Animal(void) : type("Default") 
{
    std::cout << "One ANIMAL has been created of type " << this->type << std::endl;
}

Animal::Animal(std::string type) : type(type) 
{
    std::cout << "One ANIMAL has been created of type " << this->type << std::endl;
}

Animal::Animal(Animal const & src) 
{
    *this = src;
    return ;
}

Animal::~Animal() 
{
    std::cout << "The ANIMAL of type " << this->type << " has been deleted!" << std::endl;
}

std::string   Animal::getType ()  const 
{
    return (this->type);
}

Animal &    Animal::operator=( Animal const & rhs ) 
{
    if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

