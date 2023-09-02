#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("SchrubberyForm", 145, 137 )
{
    _Target = "Random_Target";
    std::cout << "Constructeur vide de shcrubbery appele" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SchrubberyForm", 145, 137 ),
                                                                    _Target(target) 
{
    std::cout << "Constructeur Target de schrubbery appele" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("SchrubberyForm", 145, 137 )
{
    std::cout << "Constructeur de copie appele" << std::endl;
    _Target = src._Target;
    this->setStatus(src.getStatus());
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "Destrcuteur de Schrubbery est appele" <<  std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
    return(_Target);
}

void        ShrubberyCreationForm::setTarget(std::string const target)
{
    _Target = target;
}


ShrubberyCreationForm &    ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) 
{
    std::cout << "Operateur d'assignation est appele" << std::endl;
    if(this != &rhs)
    {
        this->setStatus(rhs.getStatus());
        _Target = rhs._Target;
    }    
    return (*this);
}


void        ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    this->CanExecute(executor);
      
    int hauteur = 15;
    std::string name_file = _Target + "_schrubbery";
    std::ofstream fichier(name_file);
    if (!(fichier.is_open()))
        throw AForm::FileWontOpenException();
    for (int niveau = 1; niveau <= hauteur; niveau++) 
    {
        for (int espace = 0; espace < hauteur - niveau; espace++) 
            fichier << " ";
        for (int etoile = 0; etoile < 2 * niveau - 1; etoile++) 
            fichier << "*";
        fichier << std::endl;
    }
    for (int i = 0; i < hauteur - 1; i++) 
        fichier << " ";
    fichier << "|" << std::endl;
    fichier.close();
}

AForm*       ShrubberyCreationForm::make(std::string type, std::string target, AForm* form)
{
    
    if (form == NULL && type == "Shrubbery Creation")
        return (new ShrubberyCreationForm(target));
    else
        return form;
}
