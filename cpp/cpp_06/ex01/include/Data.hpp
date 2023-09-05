#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
public:
    
    Data(void);
    Data( Data const & src );
    ~Data();

    Data & operator=( Data const & rhs ); 

    std::string str;
    int         i;
    char        c;

private:
};

#endif 
