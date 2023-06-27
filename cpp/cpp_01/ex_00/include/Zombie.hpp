#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>


class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();

    void    announce(void);
};


Zombie* new_zombie(std::string name);
void    randomChump(std::string name);

#endif
