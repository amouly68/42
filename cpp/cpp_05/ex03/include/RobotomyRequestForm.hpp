#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
    std::string _Target;
    int          _i;

public:
    
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm( RobotomyRequestForm const & src );
    ~RobotomyRequestForm();

    std::string getTarget();
    void        setTarget(std::string const target);

    RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs ); 
    void        execute(Bureaucrat const & executor);
   


    

};

#endif 
