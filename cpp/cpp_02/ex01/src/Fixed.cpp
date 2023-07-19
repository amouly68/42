#include "../include/Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
    std::cout << "Default constructeur called" << std::endl ;
    this->_value = 0;
    return;
}

Fixed::Fixed(const int numint)
{
    std::cout << "Int constructeur called" << std::endl ;
    this->_value = (numint << this->_num_of_bits) ;
    return;
}

Fixed::Fixed(const float numfloat)
{
    std::cout << "Float constructeur called" << std::endl ;
    this->_value = roundf(numfloat * 256) ;
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
        this->_value = rhs._value;
    
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

 float       Fixed::toFloat( void ) const
 {
    return (static_cast<float>(this->_value) / (256) );
 }

 int       Fixed::toInt( void ) const
 {
    return (this->_value >> this->_num_of_bits);
 }

 std::ostream &  operator<<( std::ostream & out, Fixed const & rhs)
 {
    out << rhs.toFloat();
    return (out);
 }