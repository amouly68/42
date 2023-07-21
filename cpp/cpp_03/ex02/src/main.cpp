#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap Paulo("Paulo");
    ClapTrap Toto("Toto");

    Paulo.attack("Toto");
    Paulo.display();
    Toto.takeDamage(Paulo.getAttackDamage());
    Toto.display();
    Paulo.takeDamage(4);
    Paulo.display();
    Paulo.beRepaired(1);
    Paulo.display();
    int i = 0;
    while (i++ < 50)
        Paulo.beRepaired(1);
    Paulo.takeDamage(20);

    ScavTrap Eddy("Eddy");
    Eddy.display();
    Eddy.attack("Toto");
    Toto.takeDamage(Eddy.getAttackDamage());
    Toto.display();
    Eddy.display();
    
    FragTrap Noname;
    FragTrap Marco("Marco");
    Marco.display();
    Marco.attack("Eddy");
    Eddy.takeDamage(Marco.getAttackDamage());
    Eddy.display();
    Marco.display();


    return(0);
}