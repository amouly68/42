#include "Zombie.hpp"
#include <unistd.h>

int main()
{
    
    randomChump("random1");
    Zombie* new_zombie1 = newZombie("new_zombie1");
    Zombie* new_zombie2 = newZombie("new_zombie2");
    Zombie* new_zombie3 = newZombie("new_zombie3");

    new_zombie1->announce();
    new_zombie2->announce();
    new_zombie3->announce();
    delete new_zombie1;
    delete new_zombie2;
    delete new_zombie3;

    return(0);
}