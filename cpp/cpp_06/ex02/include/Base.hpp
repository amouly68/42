#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base {
public:
    
    virtual ~Base();

   

private:
};

 Base * generate(void);
 void identify(Base* p);
 void identify(Base& p);

#endif 
