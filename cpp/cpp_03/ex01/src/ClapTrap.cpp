#include "../include/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() 
{
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
    
    std::cout << "ClapTrap constructeur par defaut" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : Name(name) 
{
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
    std::cout << "ClapTrap " << this->Name << " a ete cree" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) 
{
    *this = src;
    return ;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << this->Name << " a ete detruit" << std::endl;
}

ClapTrap &    ClapTrap::operator=( ClapTrap const & rhs ) 
{
    if(this != &rhs)
    {
        this->Name = rhs.Name;
        this->EnergyPoints = rhs.EnergyPoints;
        this->HitPoints = rhs.HitPoints;
        this->AttackDamage = rhs.AttackDamage;
    }
    
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{

    if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " attack " <<  target;
        std::cout << ", causing " << this->AttackDamage << " points of attack." <<  std::endl;
        this->EnergyPoints--;
    }

} 
void    ClapTrap::takeDamage(unsigned int amount)
{   
        if (this->HitPoints > 0 )
        {
            std::cout << "ClapTrap " << this->Name << " take damage and lose ";
            std::cout << amount << " points." <<  std::endl;
            this->HitPoints -= amount;
            if (this->HitPoints <= 0)
                std::cout <<  this->Name << " is dead." << std::endl;
        }
}
void    ClapTrap::beRepaired(unsigned int amount)
{
     if(this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " repair itself ";
        std::cout << "of " << amount << " points." <<  std::endl;
        this->HitPoints += amount;
        this->EnergyPoints--;
    }
}
std::string     ClapTrap::getName()
{
    return (this->Name);
}
int             ClapTrap::getHitPoints()
{
    return (this->HitPoints);
}

int             ClapTrap::getEnergyPoints()
{
    return (this->EnergyPoints);
}

int             ClapTrap::getAttackDamage()
{
    return (this->AttackDamage);
}

void ClapTrap::display()
{
    std::cout << this->Name <<  " : Hitpoints ==> " <<  this->HitPoints << std::endl;
    std::cout << this->Name <<  " : EnergyPoints ==> " <<  this->EnergyPoints << std::endl;
    std::cout << this->Name <<  " : AttaqeDamage ==> " <<  this->AttackDamage << std::endl;
}