#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
    
    FragTrap(void);
    FragTrap( FragTrap const & src );
    FragTrap(std::string Name);
    ~FragTrap();

    FragTrap & operator=( FragTrap const & rhs ); 
    void    highFiveGuys();
    void    attack(const std::string& target); 

private:
    

};

#endif 
