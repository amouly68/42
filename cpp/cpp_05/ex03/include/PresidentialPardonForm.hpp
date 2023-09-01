#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
    std::string _Target;

public:
    
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm( PresidentialPardonForm const & src );
    ~PresidentialPardonForm();

    std::string getTarget();
    void        setTarget(std::string const target);

    PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs ); 
    void        execute(Bureaucrat const & executor);
   


    

};

#endif 
