

#include "ScalarConverter.hpp"
#include <iostream>




int main()
{
    std::string input ("0");
    ScalarConverter::convert(input);
    input = "42.0f";
    ScalarConverter::convert(input);
    input = "nan";
    ScalarConverter::convert(input);
    input = "+inff";
    ScalarConverter::convert(input);
}