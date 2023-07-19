#include "../include/FloatFixed.hpp"

#include <iostream>

FloatFixed::FloatFixed(void):_value(0)
{
}

FloatFixed::FloatFixed(FloatFixed const & src) 
{
    *this = src;
    return;
}

FloatFixed::~FloatFixed() 
{
    // TODO: Implémenter le destructeur
}

FloatFixed &    FloatFixed::operator=( FloatFixed const & rhs ) 
{
    if(this != &rhs)
        this->_value = rhs.getRawBits();
    
    return (*this);
}

 int    FloatFixed::getRawBits( void ) const
 {
    return (this->_value);
 }

 void   FloatFixed::setRawBits( int const raw )
 {
        this->_value = raw;
 }