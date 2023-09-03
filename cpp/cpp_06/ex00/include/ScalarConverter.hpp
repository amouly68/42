#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <iomanip>

class ScalarConverter {
public:
    
    ScalarConverter(void);
    ScalarConverter( ScalarConverter const & src );
    ~ScalarConverter();

    ScalarConverter & operator=( ScalarConverter const & rhs ); 
    static void  convert(const std::string& input);

     class ImpossibleException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };

    class NonDisplayableException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };

   /* class IdentityException : public std::exception
    {
        public :
            IdentityException(const std::string& input);
            virtual const char* what() const;
        private :
            std::string message;
    };*/

private:
    

};

#endif 
