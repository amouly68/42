#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
public:
    
    Dog(void);
    Dog( Dog const & src );
    virtual ~Dog();

    Dog & operator=( Dog const & rhs ); 
    virtual void   makeSound() const;

private:
    
    Brain *_Brain;
    

};

#endif 
