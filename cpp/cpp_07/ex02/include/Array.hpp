#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <array>

template <typename T>
class Array {
public:
    
    Array(void);
    Array(unsigned int n);
    Array( Array const & src );
    ~Array();

    Array & operator=( Array const & rhs ); 

    unsigned int size(void);

private:

    unsigned int _size;    
    T*           _arr;

};

#endif 
