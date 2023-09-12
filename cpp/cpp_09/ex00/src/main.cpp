

#include "easyfind.hpp"
#include <iostream>
#include <list>




int main()
{
    std::list<int> test;
    test.push_back(1);
    test.push_back(11);
    test.push_back(42);
    test.push_back(30);
    try
    {
        easyfind(test, 42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
      try
    {
        easyfind(test, 45);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
      try
    {
        easyfind(test, 30);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return (0);

}