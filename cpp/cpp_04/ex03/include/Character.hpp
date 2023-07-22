#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

private:

    AMateria * _Inventaire [4];
    std::string _Name;

public:
    
    Character(void);
    Character (std::string name);
    Character( Character const & src );
    ~Character();

    Character & operator=( Character const & rhs ); 

    std::string const & getName() const;
    void equip(AMateria * m);
    void unequip(int idx);
    void use(int idx, ICharacter & terget);
    

};

#endif 
