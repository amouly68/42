#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    Animal* meta[10] ; 
    int i = 0;
    while(i < 10)
    {
        meta[i++] = new Dog;
        meta[i++] = new Cat;
    }
    
    i = 0;
     while(i < 10)
        delete meta[i++];
        
    return 0;
}