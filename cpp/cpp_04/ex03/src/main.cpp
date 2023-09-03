#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"



int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;


    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // AMateria* tmp1;
    // AMateria* tmp2;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp1 = src->createMateria("ice");
    // me->equip(tmp1);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp2 = src->createMateria("ice");
    // me->equip(tmp2);
    // delete (tmp2);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // me->use(2, *bob);
    // me->use(3, *bob);
    // me->use(4, *bob);
    // src->learnMateria(new Cure());
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // me->unequip(2);
    // delete (tmp1);
    // me->equip(tmp);
    // me->use(2, *bob);
    // delete bob;
    // delete me;
    // delete src;
    // return 0;


}