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
    int i = 0;
    while (i < 4)
    {
        if (src._Materia[i] != NULL)
            this->_Materia[i] = src._Materia[i]->clone();
        else  
             this->_Materia[i] = NULL; 
        i++;
    }
    return;
}


MateriaSource::~MateriaSource() 
{
    std::cout << "MateriaSource destrcuteur" << std::endl;
    int i = 0;
    while (i < 4)
    {
        if (this->_Materia[i])
            delete this->_Materia[i];
        i++;
    }
}

MateriaSource &    MateriaSource::operator=( MateriaSource const & rhs ) 
{
    int i = 0;
    while (i < 4)
    {
         if (rhs._Materia[i] != NULL)
            this->_Materia[i] = rhs._Materia[i]->clone();
        else  
             this->_Materia[i] = NULL; 
        i++;
    }
    return (*this);
}

void MateriaSource::learnMateria (AMateria * mat)
{
    int i = 0;
    while (i < 4)
    {
        if (this->_Materia[i] == NULL)
        {
            this->_Materia[i] = mat;
            return;
        }
        i++;
    }
    std::cout << "Materia Source is full" << std::endl;
    return;
}

 AMateria * MateriaSource::createMateria(std::string const & type)
 {
    AMateria * ret;
    int i = 0;
    while (i < 4)
    {
        if (this->_Materia[i] && this->_Materia[i]->getType().compare(type) == 0)
        {
            ret = _Materia[i]->clone();
            return (ret);
        }
        i++;
    }
    std::cout << "Type Inconnu" << std::endl;
    return NULL;
 }












