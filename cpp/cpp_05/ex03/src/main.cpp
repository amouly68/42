
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main()
{

     Intern test;
     AForm* form;
     Bureaucrat toto("toto", 1);
     form = test.makeForm("Robotomy Request", "target");
     delete (form);
     form = test.makeForm("Presidential Pardon", "target");
     delete (form);
     form = test.makeForm("Shrubbery Creation", "target");
     toto.executeForm(*form);
     toto.signForm(*form);
     toto.executeForm(*form);
     delete (form);

    form = test.makeForm("dsadasdsa", "target");
    

    return 0;
}