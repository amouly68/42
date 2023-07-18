#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _type(type)
{
    std::cout << this->_name << " has been created. ";
    std::cout << "He has a weapon of type " << this->_type.getType() <<  std::endl;
}

HumanA::~HumanA() 
{
    std::cout << this->_name << " has been deleted." << std::endl ;
}

void    HumanA::attack(void)
{
    std::cout <<  this->_name << " attacks with their " << this->_type.getType() << std::endl;
}
