

#include "ScalarConverter.hpp"
#include <iostream>




int main()
{
    std::cout << "\n" << "------0-----" << std::endl;
    ScalarConverter::convert("0");
    std::cout << "\n" << "--- nan----" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "\n" << "--- 42.of----"<< std::endl;
    ScalarConverter::convert("42.0f");
    
    std::cout << "\n" << "--- rien----" << std::endl;
    ScalarConverter::convert("");
    std::cout << "\n" << "-----?----" << std::endl;
    ScalarConverter::convert("?");
    std::cout << "\n" << "--- 46----"<< std::endl;
    ScalarConverter::convert("46");
    std::cout << "\n" << "--- -456.0 ----"<< std::endl;
    ScalarConverter::convert("-456.0");
    std::cout << "\n" << "---  -inff ----"<< std::endl;
    ScalarConverter::convert("-inff");
    std::cout << "\n" << "--- -2147483648 ---"<< std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << "\n" << "---  -2147483648.5 ----"<< std::endl;
     ScalarConverter::convert("-2147483648.5");

}