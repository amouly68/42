
#include <unistd.h>
#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    
    std::cout << "L'adresse de la string : " << &str << std::endl;
    std::cout << "L'adresse stockee dans stringPTR : " << stringPTR << std::endl;
    std::cout << "L'adresse stockee dans stringREF : " << &stringREF << std::endl;

    std::cout << "La valeur de string : " << str << std::endl;
    std::cout << "La valeur pointee par stringPTR : " << *stringPTR << std::endl;
    std::cout << "La valeur pointee par stringREF : " << stringREF << std::endl;

    return(0);
}