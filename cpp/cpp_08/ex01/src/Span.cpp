#include "../include/Span.hpp"

#include <iostream>

Span::Span(void) 
{
    // TODO: Implémenter le constructeur
}

Span::Span(unsigned int n) : _n(n)
{
    if (_n == 0) 
    {
        std::cout << "Impossible to create span with 0 elements" << std::endl;
        Span::~Span();
    }

}

Span::Span(Span const & src) 
{
    *this = src;
    return ;
}

Span::~Span() 
{
    std::cout << "Destructor called" << std::endl;
}

Span &    Span::operator=( Span const & rhs ) 
{
    // TODO: Implémenter l'operateur d'assignemet
}

void Span::addNumber(int n)
{
    if (li.size() < _n)
        li.push_front(n);
    else    
        
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("Span is full !!");
}