#include "../include/MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource(void) 
{
    std::cout << "MateriaSource constructor" << std::endl;
    int i = 0;
    while (i < 4)
        this->_Materia[i++] = NULL;
    return;
}

MateriaSource::MateriaSource(MateriaSource const & src) 
{
    *this = src;
    return ;
}

MateriaSource::~MateriaSource() 
{
    std::cout << "MateriaSource destrcuteur" << std::endl;
}

MateriaSource &    MateriaSource::operator=( MateriaSource const & rhs ) 
{
    int i = 0;
    while (i < 4)
    {
        this->_Materia[i] = rhs._Materia[i]->clone();
        i++;
    }
}

void learnMateria (AMateria *);