
#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    
    Zombie*     newp = (Zombie *)calloc(1, sizeof(Zombie));
    newp->setname(name);
    return (newp);
}