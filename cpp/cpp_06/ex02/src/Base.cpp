#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <cstdlib>



Base::~Base() 
{
    std::cout << "Destructeur de Base" << std::endl;
}


Base* Base::generate(void)
{
    
    Base* A = new class A;
    Base* B = new class B;
    Base* C = new class C;
    
    Base* ptr[3] = {A,B,C };
    int i = rand() % 3;
    return (ptr[i]);
    
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*> (p))
        std::cout << "classe A" << std::endl;
    else if (dynamic_cast<B*> (p))
        std::cout << "classe B" << std::endl;
    else if (dynamic_cast<C*> (p))
        std::cout << "classe C" << std::endl;
    else
        std::cout << "classe inconnue" << std::endl;
}


void Base::identify(Base& p)
{
    try
    {
        dynamic_cast<A&> (p);
        std::cout << "classe A" << std::endl;
    }
    catch(const std::bad_cast)
    {
    }
      try
    {
        dynamic_cast<B&> (p);
        std::cout << "classe B" << std::endl;
    }
    catch(const std::bad_cast)
    {
    }
      try
    {
        dynamic_cast<C&> (p);
        std::cout << "classe C" << std::endl;
    }
    catch(const std::bad_cast)
    {
    }
}


