#include "../include/Fixed.hpp"

#include <iostream>

Fixed::Fixed(void)
{
    this->_value = 0;
    std::cout << "Default constructeur called" << std::endl ;
    return;
}

Fixed::Fixed(Fixed const & src) 
{
    std::cout << "Copy constructor called" << std::endl ;
    *this = src;
    return;
}

Fixed::~Fixed() 
{
    std::cout << "Default Destructor called" << std::endl;
}

Fixed &    Fixed::operator=( Fixed const & rhs ) 
{
    std::cout << "Copy assignement operator called" << std::endl;
    if(this != &rhs)
        this->_value = rhs.getRawBits();
    
    return (*this);
}

 int    Fixed::getRawBits( void ) const
 {
    std::cout << "getRawBits member Function called" << std::endl;
    return (this->_value);
 }

 void   Fixed::setRawBits( int const raw )
 {
        this->_value = raw;
 }