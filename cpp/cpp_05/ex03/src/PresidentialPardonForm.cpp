#include "../include/PresidentialPardonForm.hpp"

#include <iostream>
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PardonForm", 25, 5 )
{
    _Target = "Random_Target";
    std::cout << "Constructeur vide de Pardon appele" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PardonForm", 25, 5 ),
                                                                    _Target(target) 
{
    std::cout << "Constructeur Target de Pardon appele" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("PardonForm", 25, 5 )
{
    std::cout << "Constructeur de copie appele" << std::endl;
    _Target = src._Target;
    this->setStatus(src.getStatus());
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "Destrcuteur de Pardon est appele" <<  std::endl;
}

std::string PresidentialPardonForm::getTarget()
{
    return(_Target);
}

void        PresidentialPardonForm::setTarget(std::string const target)
{
    _Target = target;
}


PresidentialPardonForm &    PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) 
{
    std::cout << "Operateur d'assignation est appele" << std::endl;
    if(this != &rhs)
    {
        this->setStatus(rhs.getStatus());
        _Target = rhs._Target;
    }    
    return (*this);
}


void        PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    this->CanExecute(executor);
      
    std::cout << _Target << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}

AForm*     PresidentialPardonForm::make(std::string type, std::string target, AForm* form)
{
    
    if (form == NULL && type == "Presidential Pardon")
        return (new PresidentialPardonForm(target));
    else
        return form;
}
