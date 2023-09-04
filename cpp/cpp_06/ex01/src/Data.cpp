#include "../include/Data.hpp"

#include <iostream>

Data::Data(void) :str("exemple"), i(42), c('c')
{
    std::cout << "constructeur appele" << std::endl;
}

Data::Data(Data const & src) 
{
    *this = src;
    return ;
}

Data::~Data() 
{
    std::cout << "destructeur appele" << std::endl;
}

Data &    Data::operator=( Data const & rhs ) 
{
    (void) rhs;
    return (*this);
}

