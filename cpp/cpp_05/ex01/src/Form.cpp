#include "../include/Form.hpp"

#include <iostream>

Form::Form(void) : _Name("Lambda"), _Status(0), _GradeToSign(150), _GradeToExecute(150) 
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade 150 to sign and execute it" << std::endl; 
}

Form::Form(std::string name, int sign, int exec) : _Name(name), _Status(0), _GradeToSign(sign), _GradeToExecute(exec)
{
    if (sign > 150 || exec > 150)
        throw Form::GradeTooLowException();
    else if (sign < 1 || sign < 1)
        throw Form::GradeTooHighException();
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it" << std::endl; 
} 


Form::Form(Form const & src) : _Name(src._Name), _Status(src._Status), _GradeToSign(src._GradeToSign), _GradeToExecute(src._GradeToExecute)
{
    std::cout << "A form " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it" << std::endl; 
    return ;
}

Form::~Form() 
{
    std::cout << "The Form " << _Name << " has been deleted" << std::endl;
}

Form &    Form::operator=( Form const & rhs ) 
{
    if(this != &rhs)
    {
        _Status = rhs._Status;
    }
    
    return (*this);
}

const std::string   Form::getName() const
{
    return (_Name);
}

bool                Form::getStatus() const
{
    return (_Status);
}
int           Form::getGradeToSign() const
{
    return (_GradeToSign);
}

int           Form::getGradeToExecute() const
{
    return (_GradeToExecute);
}

void                Form::BeSigned(Bureaucrat& buro)
{
    if (_Status)
        throw Form::FormIsSignedException();
    if (buro.getGrade() <= _GradeToSign )
            _Status = 1;
        else
            throw Form::GradeTooLowException();
}



const char* Form::GradeTooHighException::what() const throw()
{
    return ("GRADE TOO HIGH !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("GRADE TOO LOW !");
}

const char* Form::FormIsSignedException::what() const throw()
{
    return ("Form is already signed !");
}

std::ostream& operator<<(std::ostream& os, const Form &form)
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