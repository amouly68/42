#include "../include/FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(void) 
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FRAGTRAP : constructeur par defaut" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 30;
    std::cout << "FRAGTRAP " << this->_Name << " a ete cree" << std::endl;
}


FragTrap::FragTrap(FragTrap const & src) 
{
    *this = src;
    return ;
}

FragTrap::~FragTrap() 
{
    std::cout << "FRAGTRAP : " << this->_Name << " destructor par defaut" << std::endl;
}

FragTrap &    FragTrap::operator=( FragTrap const & rhs ) 
{
    ClapTrap::operator=(rhs);
    return ( *this);
}

void    FragTrap::highFiveGuys()
{
    std::cout << this->_Name << " demande des Highfives !!!!." << std::endl;
}

void   FragTrap::attack(const std::string & target)
{
     if(this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "FRAGTRAP " << this->_Name << " attack " <<  target;
        std::cout << ", causing " << this->_AttackDamage << " points of attack." <<  std::endl;
        this->_EnergyPoints--;
    }

}