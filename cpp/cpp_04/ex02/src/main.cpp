#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    //Animal test("test");
    AAnimal* meta[10] ; 
    int i = 0;
    while(i < 8)
    {
        meta[i++] = new Dog;
        meta[i++] = new Cat;
    }
    

    Dog dog_copy(*(Dog *)meta[0]);
    i = 19;
    std::cout << std::endl << "###########################" << std::endl;
    while (i < 32)
    {
        std::cout << dog_copy.getBrain()->getIdeas(i) << std::endl;
        i++;
    }
    std::cout << "###########################" << std::endl << std::endl ;
    i = 0;
     while(i < 8)
        delete meta[i++];

    
    return 0;
}