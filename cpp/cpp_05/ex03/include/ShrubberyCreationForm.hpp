#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
    std::string _Target;

public:
    
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm( ShrubberyCreationForm const & src );
    ~ShrubberyCreationForm();

    std::string getTarget();
    void        setTarget(std::string const target);

    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs ); 
    void        execute(Bureaucrat const & executor);
   


    

};

#endif 
