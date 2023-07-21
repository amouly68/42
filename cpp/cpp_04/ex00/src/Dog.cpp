#include "../include/Dog.hpp"

#include <iostream>

Dog::Dog(void) 
{
    Animal::type = "Dog";
    std::cout << "One Dog has been created. " << std::endl;
}

Dog::Dog(Dog const & src) 
{
    *this = src;
    return ;
}

Dog::~Dog() 
{
    std::cout << "One dog has been deleted!" << std::endl;
}

Dog &    Dog::operator=( Dog const & rhs ) 
{
   if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void   Dog::makeSound() const
{
    std::cout << "OUAAAF OUAAAAF OUUUAAAAAAF" << std::endl;
}
