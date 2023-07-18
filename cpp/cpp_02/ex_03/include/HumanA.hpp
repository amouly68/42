#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
    
    HumanA(std::string name, Weapon &type);
    ~HumanA();

    void    attack();     

private:
    
    std::string _name;
    Weapon&      _type;


};

#endif 
