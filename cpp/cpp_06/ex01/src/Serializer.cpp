#include "../include/Serializer.hpp"

#include <iostream>

Serializer::Serializer(void) 
{
    std::cout << "constructeur appele" << std::endl;
}

Serializer::Serializer(Serializer const & src) 
{
    *this = src;
    return ;
}

Serializer::~Serializer() 
{
    std::cout << "destructeur appele" << std::endl;
}

Serializer &    Serializer::operator=( Serializer const & rhs ) 
{
    (void) rhs;
    return (*this);
}


uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*> (raw));
}

