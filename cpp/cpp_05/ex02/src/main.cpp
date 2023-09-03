
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

int main()
{

    ShrubberyCreationForm shrub1("garden");
    std::cout << shrub1 << std::endl;
    ShrubberyCreationForm shrub2(shrub1);
    std::cout << shrub2 << std::endl;
    
    
   
    Bureaucrat peutRienFaire("peutRienFaire",148 );
    Bureaucrat peutsigner("peutsigner",140 );
    Bureaucrat peutToutFaire("peutToutFaire",50 );

    peutRienFaire.signForm(shrub1);
    peutRienFaire.executeForm(shrub1);
    peutsigner.executeForm(shrub1);
    peutsigner.signForm(shrub1);
    peutsigner.executeForm(shrub1);
    std::cout << shrub1 << std::endl;
    peutToutFaire.executeForm(shrub1);
    shrub2.setTarget("jardin");
    peutToutFaire.executeForm(shrub2);
    peutToutFaire.signForm(shrub2);
    peutToutFaire.executeForm(shrub2);
    peutToutFaire.executeForm(shrub2);
    ShrubberyCreationForm shrub3;
    shrub3 = shrub1;
    std::cout << shrub3 << std::endl;
    ShrubberyCreationForm shrub4(shrub1);
    std::cout << shrub4 << std::endl;

    std::cout << "\n" << "\n" << " ---- LES ROBO -----" << "\n" << std::endl;
    RobotomyRequestForm Robo1("Toto");
    std::cout << Robo1 << std::endl;
    RobotomyRequestForm Robo2(Robo1);
    std::cout << Robo2 << std::endl;
    
    Bureaucrat peutRienFaire1("peutRienFaire1",148 );
    Bureaucrat peutsigner1("peutsigner1",60 );
    Bureaucrat peutToutFaire1("peutToutFaire1",1 );

    peutRienFaire1.signForm(Robo1);
    peutRienFaire1.executeForm(Robo1);
    peutsigner1.executeForm(Robo1);
    peutsigner1.signForm(Robo1);
    peutsigner1.executeForm(Robo1);
    std::cout << Robo1 << std::endl;
    peutToutFaire1.executeForm(Robo1);
    Robo2.setTarget("Dede");
    peutToutFaire1.executeForm(Robo2);
    peutToutFaire1.signForm(Robo2);
    peutToutFaire1.executeForm(Robo2);
    peutToutFaire1.executeForm(Robo2);
    peutToutFaire1.executeForm(Robo2);
    peutToutFaire1.executeForm(Robo2);
    RobotomyRequestForm Robo3;
    Robo3 = Robo1;
    std::cout << Robo3 << std::endl;
    RobotomyRequestForm Robo4(Robo1);
    std::cout << Robo4 << std::endl;

    
    std::cout << "\n" << "\n" << " ---- LES PARDON -----" << "\n" << std::endl;
   
    PresidentialPardonForm Pardon1("Toto");
    std::cout << Pardon1 << std::endl;
    PresidentialPardonForm Pardon2(Pardon1);
    std::cout << Pardon2 << std::endl;


    Bureaucrat peutRienFaire2("peutRienFaire2",148 );
    Bureaucrat peutsigner2("peutsigner2",20 );
    Bureaucrat peutToutFaire2("peutToutFaire2",1 );

    peutRienFaire2.signForm(Pardon1);
    peutRienFaire2.executeForm(Pardon1);
    peutsigner2.executeForm(Pardon1);
    peutsigner2.signForm(Pardon1);
    peutsigner2.executeForm(Pardon1);
    std::cout << Pardon1 << std::endl;
    peutToutFaire2.executeForm(Pardon1);
    Pardon2.setTarget("Dede");
    peutToutFaire2.executeForm(Pardon2);
    peutToutFaire2.signForm(Pardon2);
    peutToutFaire2.executeForm(Pardon2);
    PresidentialPardonForm Pardon3;
    Pardon3 = Pardon1;
    std::cout << Pardon3 << std::endl;
    PresidentialPardonForm Pardon4(Pardon1);
    std::cout << Pardon4 << std::endl;



    return 0;
}