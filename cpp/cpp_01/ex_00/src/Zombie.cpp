
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " has been deleted" << std::endl;
}

void Zombie::announce(void){
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl; 
}

void   Zombie::setname(std::string name){
    this->_name = name;
}