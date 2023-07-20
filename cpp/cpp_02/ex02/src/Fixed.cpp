#include "../include/Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
    this->_value = 0;
    return;
}

Fixed::Fixed(const int numint)
{
    this->_value = (numint << this->_num_of_bits) ;
    return;
}

Fixed::Fixed(const float numfloat)
{
    this->_value = roundf(numfloat * 256) ;
    return;
}


Fixed::Fixed(Fixed const & src) 
{
    *this = src;
    return;
}

Fixed::~Fixed() 
{
    //std::cout << "Default Destructor called" << std::endl;
}


/*****************   LES OPERATEURS DE CALCUL ***********************/

Fixed &    Fixed::operator=( Fixed const & rhs ) 
{
    if(this != &rhs)
        this->_value = rhs.getRawBits();
    
    return (*this);
}

Fixed     Fixed::operator+( Fixed const & rhs ) 
{
    Fixed  res;
    res.setRawBits(this->_value + rhs.getRawBits());

    return (res);
}

Fixed     Fixed::operator-( Fixed const & rhs ) 
{
    Fixed  res;
    res.setRawBits(this->_value - rhs.getRawBits());
    
    return (res);
}

Fixed     Fixed::operator*( Fixed const & rhs ) 
{
    float result;
    result = this->toFloat() * rhs.toFloat();
    Fixed  res (result);
    return (res);
}

Fixed     Fixed::operator/( Fixed const & rhs ) 
{
    float result;
    result = this->toFloat() / rhs.toFloat();
    Fixed  res (result);
    return (res);
}

/*****************   LES OPERATEURS DE COMPARAISON ***********************/

bool        Fixed::operator>(Fixed const & rhs) const
{
    return (this->_value > rhs.getRawBits());
}

bool        Fixed::operator<(Fixed const & rhs) const
{
    return (this->_value < rhs.getRawBits());
}

bool        Fixed::operator>=(Fixed const & rhs) const
{
    return (this->_value >= rhs.getRawBits());
}

bool        Fixed::operator<=(Fixed const & rhs) const
{
    return (this->_value <= rhs.getRawBits());
}

bool        Fixed::operator==(Fixed const & rhs) const
{
    return (this->_value == rhs.getRawBits());
}

bool        Fixed::operator!=(Fixed const & rhs) const
{
    return (this->_value != rhs.getRawBits());
}
   
/*****************   LES OPERATEURS D'INCREMENTATION ***********************/

 Fixed  &    Fixed::operator++()
 {
    this->_value++;
    return(*this);
 }

Fixed       Fixed::operator++(int)
{
    Fixed ret(*this);
    this->_value++;
    return(ret);
}
    
Fixed  &    Fixed::operator--()
 {
    this->_value--;
    return(*this);
 }

Fixed       Fixed::operator--(int)
{
    Fixed ret(*this);
    this->_value--;
    return(ret);
}

/*****************   MIN et MAX ***********************/

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else 
        return b;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else 
        return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a.getRawBits() < b.getRawBits())
        return b;
    else 
        return a;
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
    if (a.getRawBits() < b.getRawBits())
        return b;
    else 
        return a;
}


 int    Fixed::getRawBits( void ) const
 {
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