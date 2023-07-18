
#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    
    Zombie*     newp = new Zombie(name);
    return (newp);
}