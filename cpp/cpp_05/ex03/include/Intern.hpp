#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include <AForm.hpp>

class Intern {

private:

public:
    
    Intern(void);
    Intern( Intern const & src );
    ~Intern();

    Intern & operator=( Intern const & rhs ); 
    AForm*       makeForm(std::string form, std::string target);
};

#endif 
