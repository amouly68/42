#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm( ShrubberyCreationForm const & src );
    ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs ); 
    void        execute(Bureaucrat const & executor);

private:
    

};

#endif 
