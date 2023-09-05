#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"





Base::~Base() 
{
    std::cout << "Destructeur de Base" << std::endl;
}


Base* generate(void)
{
    
    Base* A = new class A;
    Base* B = new class B;
    Base* C = new class C;   
    Base* ptr[3] = {A,B,C };
    int i = rand() % 3;
    for (int a = 0; a < 3; a++ )
    {
        if (a != i)
            delete ptr[a];
    }
   return (ptr[i]);
   
    
}

void identify(Base* p)
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


void identify(Base& p)
{
    
    try
    {
        A& a = dynamic_cast<A&> (p);
        std::cout << "classe A" << std::endl;
        (void) a;
        return;
    }
    catch(const std::bad_cast)
    {
    }
      try
    {
        B& b = dynamic_cast<B&> (p);
        std::cout << "classe B" << std::endl;
        (void) b;
        return;
    }
    catch(const std::bad_cast)
    {
    }
      try
    {
        C& c = dynamic_cast<C&> (p);
        std::cout << "classe C" << std::endl;
        (void) c;
        return;
    }
    catch(const std::bad_cast)
    {
    }
     std::cout << "classe inconnue" << std::endl;
}


