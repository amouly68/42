#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

private:

    const std::string   _Name;
    int                 _Grade;  


public:
    
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat( Bureaucrat const & src );
    ~Bureaucrat();

    Bureaucrat & operator=( Bureaucrat const & rhs ); 
    const std::string   getName() const;
    int                 getGrade() const;
    void                increment();
    void                decrement();
    void                signForm(Form& form);

    class GradeTooHighException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };

      class GradeTooLowException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };
    

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);



#endif 
