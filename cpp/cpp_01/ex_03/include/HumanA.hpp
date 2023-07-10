#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
public:
    
    HumanA();
    ~HumanA();

    void    attack();     

private:
    
    std::string _name;
    Weapon      _type;


};

#endif /
