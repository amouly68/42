#include "../include/ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) 
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "SCAVTRAP : constructeur par defaut" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "SCAVTRAP " << this->_Name << " a ete cree" << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const & src) 
{
    *this = src;
    return ;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "SCLAVTRAP : " << this->_Name << " destructor par defaut" << std::endl;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs ) 
{
    ClapTrap::operator=(rhs);
    return ( *this);
}

void    ScavTrap::guardGate()
{
    std::cout << this->_Name << " est en mode GateKeeper." << std::endl;
}

void   ScavTrap::attack(const std::string & target)
{
     if(this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "SCAVTRAP " << this->_Name << " attack " <<  target;
        std::cout << ", causing " << this->_AttackDamage << " points of attack." <<  std::endl;
        this->_EnergyPoints--;
    }

}
