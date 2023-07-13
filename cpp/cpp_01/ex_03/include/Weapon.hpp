#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>
#include <stdlib.h>

class Weapon{
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon();

    void    setType(std::string type);
    const std::string&    getType(void) const;
};


#endif