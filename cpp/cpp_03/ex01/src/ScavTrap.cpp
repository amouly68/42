#include "../include/ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) 
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "SCAVTRAP : constructeur par defaut" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : Name(name) 
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "SCAVTRAP " << this->Name << " a ete cree" << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const & src) 
{
    *this = src;
    return ;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "SCLAVTRAP : destructor par defaut" << std::endl;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

void    ScavTrap::guardGate()
{
    std::cout << this->name << " est en mode GateKeeper." << std::endl;
}


