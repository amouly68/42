#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:

    const std::string   _Name;
    bool                _Status;
    const   int         _GradeToSign;
    const   int         _GradeToExecute;


public:
    
    Form(void);
    Form(std::string name, int sign, int exec);
    Form( Form const & src );
    ~Form();

    Form & operator=( Form const & rhs );
    const std::string   getName() const;
    bool                getStatus() const; 
    int           getGradeToSign() const;
    int           getGradeToExecute() const;
    void                BeSigned(Bureaucrat& buro);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif 
