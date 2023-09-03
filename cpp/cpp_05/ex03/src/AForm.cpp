#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

#include <iostream>

AForm::AForm(void) : _Name("Lambda"), _Status(0), _GradeToSign(150), _GradeToExecute(150) 
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade 150 to sign and execute it" << std::endl; 
}

AForm::AForm(std::string name, int sign, int exec) : _Name(name), _Status(0), _GradeToSign(sign), _GradeToExecute(exec)
{
    if (sign > 150 || exec > 150)
        throw AForm::GradeTooLowException();
    else if (sign < 1 || sign < 1)
        throw AForm::GradeTooHighException();
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it" << std::endl; 
} 


AForm::AForm(AForm const & src) : _Name(src._Name), _Status(src._Status), _GradeToSign(src._GradeToSign), _GradeToExecute(src._GradeToExecute)
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it" << std::endl; 
   
}

AForm::~AForm() 
{
    std::cout << "The Form " << _Name << " has been deleted" << std::endl;
}

AForm &    AForm::operator=( AForm const & rhs ) 
{
    std::cout << "Operateur d'assignation est appele" << std::endl;
    if(this != &rhs)
    {
        _Status = rhs._Status;
    }
    
    return (*this);
}

const std::string   AForm::getName() const
{
    return (_Name);
}

bool                AForm::getStatus() const
{
    return (_Status);
}
int           AForm::getGradeToSign() const
{
    return (_GradeToSign);
}

int           AForm::getGradeToExecute() const
{
    return (_GradeToExecute);
}

void                AForm::setStatus(bool const status)
{
    _Status = status;
}


void                AForm::BeSigned(Bureaucrat& buro)
{
    if (_Status)
        throw AForm::FormIsSignedException();
    if (buro.getGrade() <= _GradeToSign )
            _Status = 1;
        else
            throw AForm::GradeTooLowException();
}

void                AForm::CanExecute(Bureaucrat const & buro)
{
    if (!(_Status))
        throw AForm::FormIsNotSignedException();
    if (buro.getGrade() > _GradeToExecute )
        throw AForm::GradeTooLowException();
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return ("GRADE TOO HIGH !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("GRADE TOO LOW !");
}

const char* AForm::FormIsSignedException::what() const throw()
{
    return ("Form is already signed !");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
    return ("Form is not signed !");
}

const char* AForm::FileWontOpenException::what() const throw()
{
    return ("of a problem with File opening !");
}

const char* AForm::InvalidNameFormException::what() const throw()
{
    return (" the name of the form is invlaid !");
}

std::ostream& operator<<(std::ostream& os, const AForm &form)
{
    os << "Form : " << form.getName() << std::endl;
    os << "Status : " ;
    if (form.getStatus())
        os << "signed" << std::endl;
    else
        os << "unsigned" << std::endl;
    os << "Grade to sign : " << form.getGradeToSign() <<std::endl;
    os << "Grade to execute : " << form.getGradeToExecute() <<std::endl;
    return os;
}

AForm*           AForm::makeForm(std::string type, std::string target)
{
    
    AForm* form;
    form = NULL;
    form = ShrubberyCreationForm::make(type, target, form);
    form = PresidentialPardonForm::make(type, target, form);
    form = RobotomyRequestForm::make(type, target, form);
    if (form == NULL)
        throw InvalidNameFormException();
    return(form);
    
}
