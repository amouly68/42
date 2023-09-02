#include "../include/Brain.hpp"

#include <iostream>

Brain::Brain(void) 
{
    int i = 0;
    std::string fill [10] = {"unite", "dizaine", "20", "30", "40", "50", "60", "70", "80", "90"};
    while (i < 100)
    {
        this->_ideas[i] = fill[i / 10];
        i++;
    }
    std::cout << "Brain has been created and got ideas !!! "<< std::endl;
}

Brain::Brain(Brain const & src) 
{
    int i = 0;
    while (i < 100)
    {
        this->_ideas[i] = src._ideas[i];
        i++;
    }
    std::cout << "Brain copy constructor" << std::endl;
    return ;
}

Brain::~Brain() 
{
    std::cout << "Brain destructor" << std::endl;
}

Brain &    Brain::operator=( Brain const & rhs ) 
{
    int i = 0;
    if(this != &rhs)
    {
        while (i < 100)
        {
            this->_ideas[i] = rhs._ideas[i];
            i++;
        }
    }
    std::cout << "Brain Assignement operator" << std::endl;
    return (*this);
}

std::string Brain::getIdeas(int indice)
{
    return (_ideas[indice]);
}