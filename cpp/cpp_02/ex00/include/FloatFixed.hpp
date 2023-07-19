#ifndef FLOATFIXED_HPP
#define FLOATFIXED_HPP

class FloatFixed {
public:
    
    FloatFixed(void);
    FloatFixed( FloatFixed const & src );
    ~FloatFixed();

    FloatFixed & operator=( FloatFixed const & rhs ); 
    int             getRawBits( void ) const;
    void            setRawBits( int const raw );

private:

    int                     _value;
    static const int        bit_value = 8;
    

};

#endif 
