
#include "Weapon.hpp"

Weapon::Weapon() 
{
    std::cout << "Weapon has been created" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << this->_type << " has been deleted" << std::endl;
}

const std::string&    Weapon::getType(void) const{
    const std::string &ref = this->_type;
    return(ref); 
}

void   Weapon::setType(std::string type){
    this->_type = type;
}