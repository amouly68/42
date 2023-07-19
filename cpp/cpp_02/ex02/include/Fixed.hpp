#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    
    Fixed(void);
    Fixed(const int numint);
    Fixed(const float numfloat);
    Fixed(Fixed const & src );
    ~Fixed();

    Fixed &     operator=( Fixed const & rhs ); 
    Fixed       operator+( Fixed const & rhs ); 
    Fixed       operator-( Fixed const & rhs ); 
    Fixed       operator/( Fixed const & rhs ); 
    Fixed       operator*( Fixed const & rhs ); 


    bool        operator>(Fixed const & rhs) const;
    bool        operator<(Fixed const & rhs)const;
    bool        operator>=(Fixed const & rhs)const;
    bool        operator<=(Fixed const & rhs)const;
    bool        operator==(Fixed const & rhs)const;
    bool        operator!=(Fixed const & rhs)const;

    Fixed  &    operator++();
    Fixed       operator++(int);    
    Fixed  &    operator--();
    Fixed       operator--(int);  

    static Fixed & min(Fixed & a, Fixed & b)
    {
        if (a < b)
            return a;
        else 
            return b;
    }   ;
    static Fixed & min(const Fixed & a, const Fixed & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed & max(const Fixed & a, const Fixed & b);


    int         getRawBits( void ) const;
    void        setRawBits( int const raw );
    float       toFloat( void ) const;
    int         toInt( void ) const;

private:

    int                     _value;
    static const int        _num_of_bits = 8;
    

};

std::ostream &  operator<<( std::ostream & out, Fixed const & rhs);

#endif 
