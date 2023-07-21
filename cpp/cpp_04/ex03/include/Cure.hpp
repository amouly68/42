#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{

private:

public:
    
    Cure(void);
    Cure( Cure const & src );
    virtual ~Cure();

    Cure & operator=( Cure const & rhs ); 

    virtual AMateria* clone() const ;
    virtual void use (ICharacter & target);

    

};

#endif 
