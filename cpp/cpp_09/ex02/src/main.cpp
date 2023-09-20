

#include "PmergeMe.hpp"



int main(int ac, char **av) 

{
    PmergeMe test;
    
    for (int i = 1; i < ac; i++)
        test.add_vect(atoi(av[i]));
    test.print_vect();




    return 0;
}

