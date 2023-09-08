#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <array>

template <typename T>
class Array {
public:
    
    Array(void) 
    {
        _arr = new T [0];
    };

    Array(unsigned int n) : _size(n)
    {
        _arr = new T [n] ;
    };
    
    Array( Array const & src ) : _size(src._size)
    {
        _arr = new T [_size];
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
    };

    ~Array()
    {
        delete _arr;
    };

    Array & operator=( Array const & rhs )
    {
        _size = rhs._size;
        delete _arr;
        _arr = new T [_size];
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = rhs._arr[i];
        return (*this);
    }; 

     class NoIndexException : public std::exception
    {
        public : 
            virtual const char* what() const throw()
            {
                return ("No elements at this index");
            };
    };


    T & operator[](unsigned int const & n )
    {
        if (n >= _size)
            throw NoIndexException();
        return (_arr[n]);
    };

    unsigned int size(void)
    {
    return (_size); 
    };

private:

    unsigned int _size;    
    T*           _arr;

};

#endif 
