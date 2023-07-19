
#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name){
    
    int i = 0;
    Zombie*     newp = new Zombie[n]();

    while (i < n)
        newp[i++].setname(name);

    return (newp);
}