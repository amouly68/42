#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    
    Cat(void);
    Cat( Cat const & src );
    virtual ~Cat();

    Cat & operator=( Cat const & rhs ); 
    virtual void   makeSound() const;

private:
    Brain *_Brain;
    

};

#endif 
