#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_type = NULL;
    std::cout << this->_name << " has been created. " << std::endl;
}

HumanB::~HumanB() 
{
    std::cout << this->_name << " has been deleted." << std::endl ;
}

void    HumanB::attack(void)
{
    if (_type)
        std::cout <<  this->_name << " attacks with their " << this->_type->getType() << std::endl;
    else
        std::cout << this->_name << " attacks." << std::endl; 
}

void    HumanB::setWeapon(Weapon& type)
{
    this->_type = (Weapon*) &type;
}

