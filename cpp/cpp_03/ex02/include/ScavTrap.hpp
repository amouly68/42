#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
    
    ScavTrap(void);
    ScavTrap( ScavTrap const & src );
    ScavTrap(std::string Name);
    ~ScavTrap();

    ScavTrap & operator=( ScavTrap const & rhs ); 
    void    guardGate();
    void    attack(const std::string& target); 

private:
    

};

#endif 
