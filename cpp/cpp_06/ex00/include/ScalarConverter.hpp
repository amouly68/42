#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter {
public:
    
    ScalarConverter(void);
    ScalarConverter( ScalarConverter const & src );
    ~ScalarConverter();

    ScalarConverter & operator=( ScalarConverter const & rhs ); 
    static void  convert(const std::string& input);

private:
    

};

#endif 
