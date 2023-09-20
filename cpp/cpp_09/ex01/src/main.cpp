

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN test;
        test.setInput(av[1]);
    }
    else
        std::cout << "wrong number of args" << std::endl;

}