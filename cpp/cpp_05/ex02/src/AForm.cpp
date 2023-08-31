#include "../include/AForm.hpp"

#include <iostream>

AForm::AForm(void) : _Name("Lambda"), _Status(0), _GradeToSign(150), _GradeToExecute(150), _Target("No target")
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade 150 to sign and execute it" << std::endl; 
}



AForm::AForm(AForm const & src) : _Name(src._Name), _Status(src._Status), _GradeToSign(src._GradeToSign), _GradeToExecute(src._GradeToExecute)
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it" << std::endl; 
    return ;
}

AForm::~AForm() 
{
    std::cout << "The Form " << _Name << " has been deleted" << std::endl;
}

AForm &    AForm::operator=( AForm const & rhs ) 
{
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

void                AForm::BeSigned(Bureaucrat& buro)
{
    try
    {
        if (_Status)
            throw AForm::FormIsSignedException();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
        return;
    }
    try
    {
        if (buro.getGrade() <= _GradeToSign )
            _Status = 1;
        else
            throw AForm::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
       std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    buro.signForm(*this);
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
    return ("AForm is already signed !");
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