#include "../include/Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(void) :  _Name("NO NAME"), _Grade(150)
{
    std::cout << "A bureaucrat \"NO NAME\" has been created with the default grade of 150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name) 
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _Grade = grade;
    std::cout << _Name << " has been created with the grade of " << _Grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :  _Name(src._Name), _Grade(src._Grade)
{
    std::cout << _Name << " has been created with the grade of " << _Grade << std::endl;
    return ;
}

Bureaucrat::~Bureaucrat() 
{
   std::cout << "Bureaucrat " << _Name << " has been destroyed !" << std::endl;
}

Bureaucrat &    Bureaucrat::operator=( Bureaucrat const & rhs ) 
{
    std::cout << "Operateur d'assignation est appele" << std::endl;
    if(this != &rhs)
    {
        _Grade = rhs._Grade;
    }
    
    return (*this);
}

const std::string   Bureaucrat::getName() const
{
    return (_Name);
}
int                 Bureaucrat::getGrade() const
{
    return (_Grade);
}
void                Bureaucrat::increment()
{
    if (_Grade == 1)
       throw Bureaucrat::GradeTooHighException(); 
    std::cout << "Grade of " << _Name << " has been incremented from " << _Grade << " to " << _Grade - 1 << std::endl;
    _Grade--; 
}
void                Bureaucrat::decrement()
{
    if (_Grade == 150)
       throw Bureaucrat::GradeTooLowException(); 
    std::cout << "Grade of " << _Name << " has been decremented from " << _Grade << " to " << _Grade + 1 << std::endl;
    _Grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GRADE TOO HIGH, GRADE MAX IS 1 !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GRADE TOO LOW, GRADE MIN IS 150 !");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &buro)
{
    os << buro.getName() << ", bureaucrat grade " << buro.getGrade();
    return os;
}