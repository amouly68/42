

#include "Span.hpp"
#include <iostream>
#include <iterator>




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

    Span sp = Span(5);
    sp.addNumber(6); 
    sp.addNumber(3); 
    sp.addNumber(17); 
    sp.addNumber(9); 
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl; 
    std::cout << sp.longestSpan() << std::endl;

    Span sp2(3);
    std::list<int> li;
    li.push_back(1);
    li.push_back(3);
    li.push_back(5);
    li.push_back(7);

    std::vector<int> vect;
    vect.push_back(40);
    vect.push_back(41);
    vect.push_back(100);

    try
    {
        sp2.fill(li.begin(), li.end());
        std::cout << sp2.shortestSpan() << std::endl; 
        std::cout << sp2.longestSpan() << std::endl;
    }
       
     catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        sp2.fill(vect.begin(), vect.end());
        std::cout << sp2.shortestSpan() << std::endl; 
        std::cout << sp2.longestSpan() << std::endl;
    }
       
     catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }



    return (0);

}