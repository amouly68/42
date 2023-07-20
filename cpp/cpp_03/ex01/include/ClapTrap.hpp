#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
    
    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap( ClapTrap const & src );
    ~ClapTrap();

    ClapTrap & operator=( ClapTrap const & rhs ); 

    void attack(const std::string& target); 
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void display();

    std::string getName();
    int         getHitPoints();
    int         getEnergyPoints();
    int         getAttackDamage();

    std::string Name;
    int         HitPoints;
    int         EnergyPoints;
    int         AttackDamage;
    

private:

    
    

};

#endif 
