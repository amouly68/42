#include "../include/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : _Name("The_ONE_who_got_No_Name")
{
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
    
    std::cout << "ClapTrap constructeur par defaut" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : _Name(name) 
{
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
    std::cout << "ClapTrap " << this->_Name << " a ete cree" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) 
{
    *this = src;
    return ;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << this->_Name << " a ete detruit" << std::endl;
}

ClapTrap &    ClapTrap::operator=( ClapTrap const & rhs ) 
{
    if(this != &rhs)
    {
        this->_Name = rhs._Name;
        this->_EnergyPoints = rhs._EnergyPoints;
        this->_HitPoints = rhs._HitPoints;
        this->_AttackDamage = rhs._AttackDamage;
    }
    
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{

    if(this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_Name << " attack " <<  target;
        std::cout << ", causing " << this->_AttackDamage << " points of attack." <<  std::endl;
        this->_EnergyPoints--;
    }

} 
void    ClapTrap::takeDamage(unsigned int amount)
{   
        if (this->_HitPoints > 0 )
        {
            std::cout << "ClapTrap " << this->_Name << " take damage and lose ";
            std::cout << amount << " points." <<  std::endl;
            this->_HitPoints -= amount;
            if (this->_HitPoints <= 0)
                std::cout <<  this->_Name << " is dead." << std::endl;
        }
}
void    ClapTrap::beRepaired(unsigned int amount)
{
     if(this->_EnergyPoints > 0 && this->_HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_Name << " repair itself ";
        std::cout << "of " << amount << " points." <<  std::endl;
        this->_HitPoints += amount;
        this->_EnergyPoints--;
    }
}
std::string     ClapTrap::getName()
{
    return (this->_Name);
}
int             ClapTrap::getHitPoints()
{
    return (this->_HitPoints);
}

int             ClapTrap::getEnergyPoints()
{
    return (this->_EnergyPoints);
}

int             ClapTrap::getAttackDamage()
{
    return (this->_AttackDamage);
}

void ClapTrap::display()
{
    std::cout << this->_Name <<  " : Hitpoints ==> " <<  this->_HitPoints << std::endl;
    std::cout << this->_Name <<  " : EnergyPoints ==> " <<  this->_EnergyPoints << std::endl;
    std::cout << this->_Name <<  " : AttaqeDamage ==> " <<  this->_AttackDamage << std::endl;
}