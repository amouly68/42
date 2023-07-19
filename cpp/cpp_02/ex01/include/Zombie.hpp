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

    void    setname(std::string name);
    void    announce(void);
};


Zombie* zombieHorde(int n, std::string name);

#endif