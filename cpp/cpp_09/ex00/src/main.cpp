

#include "BitcoinExchange.hpp"
#include <iostream>
#include <list>




int main(int ac, char **av)
{
    
    if (ac == 2)
    {
        BitcoinExchange test;
        test.setInput(av[1]);
        test.print_input();

    }
    else 
        std::cout << "wrong number of args" << std::endl;
    
    return (0);

}