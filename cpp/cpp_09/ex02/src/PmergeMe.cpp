#include "../include/PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe(void) 
{
    // TODO: Implémenter le constructeur
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
    *this = src;
    return ;
}

PmergeMe::~PmergeMe() 
{
    // TODO: Implémenter le destructeur
}

PmergeMe &    PmergeMe::operator=( PmergeMe const & rhs ) 
{
    (void) rhs;
    return (*this);
}

void    PmergeMe::add_vect(int i)
{
    vec.push_back(i);
}

void    PmergeMe::print_vect()
{
    std::cout << "Before :   ";
    for(std::vector<int>::size_type i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ";
    std::cout << std::endl;
}

