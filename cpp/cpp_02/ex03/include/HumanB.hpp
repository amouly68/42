#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
    
    HumanB(std::string name);
    ~HumanB();

    void    attack();
    void    setWeapon(Weapon &type);   

private:
    
    std::string     _name;
    Weapon*         _type;


};

#endif 
