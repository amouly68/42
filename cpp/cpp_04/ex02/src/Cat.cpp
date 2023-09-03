#include "../include/Cat.hpp"

#include <iostream>

Cat::Cat(void)   
{
    AAnimal::type = "Cat";
    _Brain = new Brain();
    std::cout << "One Cat has been created. " << std::endl;
}

Cat::Cat(Cat const & src) 
{    
    *this = src;
    std::cout << "cat copy connstructor" << std::endl;
    return ;
}

Cat::~Cat() 
{
    std::cout << "One Cat has been deleted!" << std::endl;
    delete _Brain;
}

Cat &    Cat::operator=( Cat const & rhs ) 
{
     if(this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void   Cat::makeSound() const
{
    std::cout << "MMMIIIIIIAAAAAAAAOUUUUUU" << std::endl;
}

Brain *    Cat::getBrain()
 {
    return (this->_Brain);
 }

