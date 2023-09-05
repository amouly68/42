

#include "Base.hpp"
#include <iostream>



int main()
{
    std::srand(std::time(0));
    
    
    Base* test;
    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";
    

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
    std::cout << "\n";

    test = generate();
    std::cout << "Pointeur  : ";
    identify(test);
    std::cout << "Reference  : ";
    identify(&(*test));
    delete (test);
}