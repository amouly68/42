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


public:
    
    AForm(void);
    AForm(std::string name, int sign, int exec);
    AForm( AForm const & src );
    virtual ~AForm();

    AForm & operator=( AForm const & rhs );
    const std::string   getName() const;
    bool                getStatus() const; 
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;
    void                BeSigned(Bureaucrat& buro);
    void                CanExecute(Bureaucrat const & buro);
    virtual void        execute(Bureaucrat const & executor) = 0;
    void                setStatus(bool const status);
    static AForm*              makeForm(std::string type, std::string target);

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

    class FormIsNotSignedException : public std::exception
     {
        public : 
            virtual const char* what() const throw();
    };

    class FileWontOpenException : public std::exception
     {
        public : 
            virtual const char* what() const throw();
    };

    class InvalidNameFormException : public std::exception
     {
        public : 
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 
