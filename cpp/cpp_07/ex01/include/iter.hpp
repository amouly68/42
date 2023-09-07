#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <array>

template <typename T>
void iter(T* arr, int length , void (*f) (T elem))
{
    int a = 0;
    while( a < length)
    {
        f(arr[a]);
        a++;
    }    
}

template <typename T, std::size_t N>
void iter(std::array<T, N > &arr, int length, void (*f) (T elem))
{
    int a = 0;
    while( a < length)
    {
        f(arr[a]);
        a++;
    }    
}

#endif 
