#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
public:
    
    Dog(void);
    Dog( Dog const & src );
    virtual ~Dog();

    Dog & operator=( Dog const & rhs ); 
    virtual void   makeSound() const;

private:
    

};

#endif 
