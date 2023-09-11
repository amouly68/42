

#include "Span.hpp"
#include <iostream>




int main()
{
    Span test(5);

     try
    {
    test.addNumber(6);
    test.addNumber(11);
    test.addNumber(42);
    test.addNumber(35);
    test.addNumber(30);
    test.addNumber(39);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "shortest span : " << test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        std::cout << "longest span : " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    Span test2(1);
      try
    {
    test.addNumber(6);
    test.addNumber(11);
    test.addNumber(42);
    test.addNumber(35);
    test.addNumber(30);
    test.addNumber(39);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        std::cout << "shortest span : " << test2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    test2 =test;
    try
    {
        std::cout << "shortest span : " << test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        std::cout << "longest span : " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);

}