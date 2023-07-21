#include "../include/DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(void) 
{
    this->FragTrap::_HitPoints = 100;
    this->ScavTrap::_EnergyPoints = 50;
    this->FragTrap::_AttackDamage = 30;
    std::cout << "DIAMONTRAP: constructeur par defaut" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _Name(name)
{
    this->FragTrap::_HitPoints = 100;
    this->ScavTrap::_EnergyPoints = 50;
    this->FragTrap::_AttackDamage = 30;
    std::cout << "DIAMONTRAP: " << this->_Name << " a ete cree" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) 
{
    *this = src;
    return ;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DIAMONDTRAP : " << this->_Name << " destructor par defaut" << std::endl;
}

DiamondTrap &    DiamondTrap::operator=( DiamondTrap const & rhs ) 
{
    ClapTrap::operator=(rhs);
    return ( *this);
}

void   DiamondTrap::attack(const std::string & target)
{
    this->ScavTrap::attack(target);
}

void   DiamondTrap::whoAmI()
{
    std::cout << "DIAMONDTRAP :  I AM " << this->_Name;
    std::cout << " AND MY CLAP NAME IS " << this->ClapTrap::_Name << " !!!" <<  std::endl;
}