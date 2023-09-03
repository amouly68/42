#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
    
    Cat(void);
    Cat( Cat const & src );
    virtual ~Cat();

    Cat & operator=( Cat const & rhs ); 
    virtual void   makeSound() const;
    Brain *    getBrain();

private:
    Brain *_Brain;
    

};

#endif 
