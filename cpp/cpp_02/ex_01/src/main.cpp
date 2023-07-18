#include "Zombie.hpp"
#include <unistd.h>

int main()
{
    int i = 0;
    int n = 10;
    Zombie *new_horde = zombieHorde(n, "Paulo");

    while (i < n)
        new_horde[i++].announce();
    delete [] new_horde;
    return(0);
}