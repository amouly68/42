

#include "BitcoinExchange.hpp"
#include <iostream>
#include <list>




int main(int ac, char **av)
{
    
    if (ac == 2)
    {
        BitcoinExchange test;
        test.setInput(av[1]);
        //test.print_rates();
    }
    else 
        std::cout << "Error: could not open file" << std::endl;
    
    return (0);

}