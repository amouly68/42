#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
public:
    
    Dog(void);
    Dog( Dog const & src );
    virtual ~Dog();

    Dog & operator=( Dog const & rhs ); 
    virtual void   makeSound() const;
    Brain *    getBrain();

private:
    
    Brain *_Brain;
    

};

#endif 
