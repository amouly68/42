#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
    
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap( DiamondTrap const & src );
    ~DiamondTrap();

    DiamondTrap & operator=( DiamondTrap const & rhs ); 

    void    attack(const std::string& target); 
    void    whoAmI();


    private:
    
    std::string _Name;

};

#endif 
