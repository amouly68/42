
#include "Harl.hpp"


int main(int ac, char **av) 
{
    if (ac == 2)
    {
        Harl    test;
        std::string input(av[1]);
        test.complain(input);
    }
    else
        std::cout << "Wrong number of arguments bye" << std::endl;
    return(0);
}