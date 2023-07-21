#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{

private:

public:
    
    Ice(void);
    Ice( Ice const & src );
    virtual ~Ice();

    Ice & operator=( Ice const & rhs ); 

    virtual AMateria* clone() const ;
    virtual void use (ICharacter & target);

    

};

#endif 
