#include "../include/RobotomyRequestForm.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RoboForm", 72, 45 )
{
    _Target = "Random_Target";
    _i = 0; 
    std::cout << "Constructeur vide de Robo appele" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RoboForm", 72, 45 ),
                                                                    _Target(target) 
{
    _i = 0;
    std::cout << "Constructeur Target de Robo appele" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("RoboForm", 72, 45 )
{
    std::cout << "Constructeur de copie appele" << std::endl;
    _Target = src._Target;
    _i = 0;
    this->setStatus(src.getStatus());
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "Destrcuteur de Robo est appele" <<  std::endl;
}

std::string RobotomyRequestForm::getTarget()
{
    return(_Target);
}

void        RobotomyRequestForm::setTarget(std::string const target)
{
    _Target = target;
}


RobotomyRequestForm &    RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) 
{
    std::cout << "Operateur d'assignation est appele" << std::endl;
    if(this != &rhs)
    {
        this->setStatus(rhs.getStatus());
        _Target = rhs._Target;
    }    
    return (*this);
}


void        RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    this->CanExecute(executor);
      
    std::cout << "BRUIT DE PERCEUSE " << std::endl << "BRUIT DE PERCEUSE " << std::endl ;
    _i++;
    if (_i % 2 == 0)
        std::cout << _Target << " a ete robotomise !!" << std::endl;
    else
        std::cout << "La robotomisation a echoué,  " << _Target << " est sauf !!" << std::endl;
}