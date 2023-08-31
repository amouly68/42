
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
   
    
    Bureaucrat Mark("Mark", 55);
    
    Bureaucrat BOSS("Boss", 1);
    std::cout << BOSS << std::endl;
    Form FormulaireA("Form A", 40, 20);
    Form FormulaireB("Form B", 65, 20);
    std::cout << FormulaireA << std::endl << std::endl << FormulaireB ;
    
     


    std::cout << std::endl << std::endl << "Essai 1 Mark veut signer un form qu'il ne peut pas" << std::endl;
    BOSS.signForm(FormulaireA);


    std::cout << std::endl << std::endl << "Essai 2 Boss va essayer de signer fois le form A";
    std::cout << " qui est dejà signé et Mark va signer le formB qu'il peut signer."<< std::endl;
    std::cout << FormulaireA ;
    BOSS.signForm(FormulaireA);
    Mark.signForm(FormulaireB);
    std::cout << FormulaireB ;




    return 0;
}