
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
    Bureaucrat Bob("Bob", 30);
    std::cout << Bob << std::endl;
    Bob.decrement();
    std::cout << Bob << std::endl;
    Bob.increment();
    std::cout << Bob << std::endl;
    Bureaucrat Bob2(Bob);
    std::cout << Bob2 << std::endl;
    Bob.increment();
    std::cout << Bob << " ------------- " << Bob2 << std::endl;
    Bureaucrat Alex;
    Bureaucrat Mark("Mark", 55);
    Bureaucrat BOSS("Boss", 1);
    std::cout << BOSS << std::endl;

    Form FormulaireA("Form A", 40, 20);
    std::cout << FormulaireA ;
    FormulaireA.BeSigned(Mark);


    }
    

    catch (std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}