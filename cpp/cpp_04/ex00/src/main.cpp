#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound(); 
    
    
    const WrongAnimal* wrong = new WrongCat();
    std::cout << wrong->getType() << " " << std::endl; 
    wrong->makeSound(); 


    delete wrong;
    delete i;
    delete meta;
    delete j;
    return 0;
}