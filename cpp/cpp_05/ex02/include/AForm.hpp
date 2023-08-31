#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:

    const std::string   _Name;
    bool                _Status;
    const   int         _GradeToSign;
    const   int         _GradeToExecute;
    const std::string   _Target;


public:
    
    AForm(void);
    AForm( AForm const & src );
    ~AForm();

    AForm & operator=( AForm const & rhs );
    const std::string   getName() const;
    bool                getStatus() const; 
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;
    void                BeSigned(Bureaucrat& buro);
    virtual void        execute(Bureaucrat const & executor) = 0;

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

    class FormIsSignedException : public std::exception
     {
        public : 
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 
