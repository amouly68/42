

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
const char*  ScalarConverter::ImpossibleException::what() const throw()
{
    return ("impossible");
}

const char*  ScalarConverter::NonDisplayableException::what() const throw()
{
    return (" Non Displayable");
}

/*ScalarConverter::IdentityException::IdentityException(const std::string& input) : message(input) 
{}

const char*  ScalarConverter::IdentityException::what() const throw()
{
    return (ScalarConverter::IdentityException::message.c_str());
}*/


bool is_int(const std::string& input)
{
    unsigned long int i = 0;
    if (input[i] == '-')
        i++;
    while(input[i] && std::isdigit(input[i]))
        i++;
    return (!input.empty() && i == input.length());
}

bool is_float(const std::string& input)
{
    unsigned long int i = 0;
    if (input[i] == '-')
        i++;
    while(input[i] && std::isdigit(input[i]))
        i++;
    if (input[i] == '.')
        i++;
    else 
        return (0);
    while(input[i] && std::isdigit(input[i]))
        i++;
    if (input[i] == 'f')
        i++;
    else 
        return (0);
    return (!input.empty() && i == input.length());
}

bool is_double(const std::string& input)
{
    unsigned long int i = 0;
    if (input[i] == '-')
        i++;
    while(input[i] && std::isdigit(input[i]))
        i++;
    if (input[i] == '.')
        i++;
    else 
        return (0);
    while(input[i] && std::isdigit(input[i]))
        i++;
    return (!input.empty() && i == input.length());
}



char toChar(const std::string& input) 
{
    if (input == "nan" || input == "+inf"|| input == "-inf" ||
        input == "nanf" || input == "+inff"|| input == "-inff" )
            //throw ScalarConverter::ImpossibleException();
            throw std::string ("impossible");
    if(input.length() == 1 && std::isprint(input[0]))
        return (input[0]);
    try{
        if(is_int(input) && std::stoi(input) >= CHAR_MIN && std::stoi(input) <= CHAR_MAX)
            return (static_cast<char> (std::stoi(input)));   
        if(is_double(input) && std::stod(input) >= CHAR_MIN && std::stod(input) <= CHAR_MAX)
            return (static_cast<char> (std::stod(input)));  
        if(is_float(input) && std::stof(input) >= CHAR_MIN && std::stof(input) <= CHAR_MAX)
            return (static_cast<char> (std::stof(input))); 
        else
            //throw ScalarConverter::NonDisplayableException();
            throw std::string ("Non Displayable");
    }
    catch (std::out_of_range &e)
    {
        throw std::string ("TOO BIG");
    }
}

int toInt(const std::string& input) 
{
    if (input == "nan" || input == "+inf"|| input == "-inf" ||
        input == "nanf" || input == "+inff"|| input == "-inff" )
        //throw ScalarConverter::ImpossibleException();
        throw std::string ("impossible");
    if(input.length() == 1 && std::isprint(input[0]))
        return (static_cast<int>(input[0]));
    try
    {
        if(is_int(input))
        return ((std::stoi(input)));   
        if(is_double(input))
            return (static_cast<int> (std::stod(input)));  
        if(is_float(input))
            return (static_cast<int> (std::stof(input))); 
        else
            //throw ScalarConverter::NonDisplayableException();
            throw std::string ("Non Displayable");
    }
    catch (std::out_of_range &e)
    {
        throw std::string ("TOO BIG");
    }
}

double toDouble(const std::string& input) 
{
    if (input == "nan" || input == "+inf"|| input == "-inf")
       // throw ScalarConverter::IdentityException(input);
       throw(input);
    if (input == "nanf" || input == "+inff"|| input == "-inff" )
    {
        //input.erase(input.size()-1);
        //throw ScalarConverter::IdentityException(input);
        std::string ret = input.substr(0, input.length() - 1);
        throw (ret);
    }
    if(input.length() == 1 && std::isprint(input[0]))
        return (static_cast<double>(input[0]));
    try{
        if(is_int(input))
            return (static_cast<double> (std::stoi(input)));   
        if(is_double(input))
            return ( (std::stod(input)));  
        if(is_float(input))
            return (static_cast<double>(std::stof(input))); 
        else
            //throw ScalarConverter::NonDisplayableException();
            throw std::string ("Non Displayable");
    }       
    catch (std::out_of_range &e)
    {
        throw std::string ("TOO BIG");
    }
}

char toFloat(const std::string& input) 
{
    if (input == "nan" || input == "+inf"|| input == "-inf")
    {
        std::string ret = input + 'f';
       // throw ScalarConverter::IdentityException(input);
       throw (ret);
    }    
    if (input == "nanf" || input == "+inff"|| input == "-inff" )
       // throw ScalarConverter::IdentityException(input);
       throw (input);
    if(input.length() == 1 && std::isprint(input[0]))
        return (static_cast<float>(input[0]));
    try{
        if(is_int(input))
            return (static_cast<float> (std::stoi(input)));   
        if(is_double(input))
            return (static_cast<float> (std::stod(input)));  
        if(is_float(input))
            return ((std::stof(input))); 
        else
            //throw ScalarConverter::NonDisplayableException();
            throw std::string ("Non Displayable");
    }
    catch (std::out_of_range &e)
    {
        throw std::string ("TOO BIG");
    }
}


void ScalarConverter::convert(const std::string& input)
{
    try{
        std::cout << "char : ";
        char a = toChar(input);
        std::cout << "'" << a << "'" << std::endl; 
    }
    /*catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }*/
    catch (std::string &e)
    {
        std::cout << e << std::endl; 
    }


    try{
        std::cout << "int : ";
        int b = toInt(input);
        std::cout << b << std::endl; 
    }
    catch (std::string &e)
    {
        std::cout << e << std::endl; 
    }
    
   try{
        std::cout << "Float : ";
        float c = toFloat(input);
        if (c - static_cast<int>(c) == 0)
            std::cout << std::fixed << std::setprecision(1);
        std::cout << c << "f"<< std::endl;
    }
    catch (std::string &e)
    {
        std::cout << e << std::endl; 
    }
    try{
        std::cout << "Double : ";
        double d = toDouble(input);
        if (d - static_cast<int>(d) == 0)
            std::cout << std::fixed << std::setprecision(1);
        std::cout << d << std::endl; 
    }
    catch (std::string &e)
    {
        std::cout << e << std::endl; 
    }

}
