#include "../include/WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) 
{
    WrongAnimal::type = "WrongCat";
    std::cout << "One WRONG Cat has been created. " << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) 
{
    *this = src;
    return ;
}

WrongCat::~WrongCat() 
{
    std::cout << "One WRONG Cat has been deleted!" << std::endl;
}

WrongCat &    WrongCat::operator=( WrongCat const & rhs ) 
{
    if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void   WrongCat::makeSound() const
{
    std::cout << "MMMIIIIIIAAAAAAAAOUUUUUU" << std::endl;
}

