

#include "../include/ScalarConverter.hpp"


ScalarConverter::ScalarConverter(void) 
{
   std::cout << "Constrcuteur de ScalarConverter appele" <<std::endl ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) 
{
    *this = src;
    return ;
}

ScalarConverter::~ScalarConverter() 
{
    std::cout << "Destructeur de ScalarConverter appele" <<std::endl ;
}

ScalarConverter &    ScalarConverter::operator=( ScalarConverter const & rhs ) 
{
    (void) rhs;
    return (*this);
}

void printConver(char a, int i, float f, double d)
{
    if (d - static_cast<int>(d) == 0)
        std::cout << std::fixed << std::setprecision(1); 
    std::cout << "char : " << a << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float : " << f << "f" << std::endl;
    std::cout << "double : " << d << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if(input.length() == 1 && std::isprint(input[0]))
        printConver(input[0], static_cast <int>(input[0]),
                    static_cast <float>(input[0]), static_cast <double>(input[0] ));
    

}