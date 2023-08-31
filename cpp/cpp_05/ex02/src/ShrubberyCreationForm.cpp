#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) 
{
    // TODO: Implémenter le constructeur
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _Name("Schrubbery form"), _Status(0), 
                                _GradeToSign(145), _GradeToExecute(137),
                                _Target(target)
{
    std::cout << "A " << _Name << " has been created, not signed. You Need grade ";
    std::cout << _GradeToSign << " to sign it and grade " << _GradeToExecute << " to execute it. ";
    std::cout << "Its target is " << _Target << std::endl; 
} 

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) 
{
    *this = src;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    // TODO: Implémenter le destructeur
}

ShrubberyCreationForm &    ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}


 void        SchrubberyCreationForm::execute(Bureaucrat const & executor)
 {
    
    std::cout << "Form is executed by " << executor.getName()  << std::endl;
 }
