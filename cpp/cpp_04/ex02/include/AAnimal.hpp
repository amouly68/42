#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
public:
    
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal( AAnimal const & src );
    virtual ~AAnimal();

    AAnimal & operator=( AAnimal const & rhs ); 
    std::string    getType() const;
    virtual void   makeSound() const = 0;

protected:

    std::string type;

};

#endif 
