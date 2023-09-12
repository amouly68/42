
#include "../include/Span.hpp"

#include <iostream>

Span::Span(void) 
{
    // TODO: Implémenter le constructeur
}

Span::Span(unsigned int n)
{
    if (n == 0) 
    {
        std::cout << "Impossible to create span with 0 elements" << std::endl;
        Span::~Span();
    }
    else
        _n = n ;

}

Span::Span(Span const & src) : _n (src._n)
{
    for (unsigned int i = 0; i < src.vec.size(); i++ )
        vec.push_back(src.vec[i]);
}

Span::~Span() 
{
    std::cout << "Destructor called" << std::endl;
}

Span &    Span::operator=( Span const & rhs ) 
{
    _n = rhs._n;
    for (unsigned int i = 0; i < rhs.vec.size(); i++ )
        vec.push_back(rhs.vec[i]);
    return (*this);
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("Span is full !!");
}

const char* Span::OnlyOneElementException::what() const throw()
{
    return ("No span possible because only one element !");
}

const char* Span::RangetoowideException::what() const throw()
{
    return ("Could'nt fill because the range is too wide !");
}

void Span::addNumber(int n)
{
    if (vec.size() < _n)
        vec.push_back(n);
    else    
        throw SpanIsFullException();       
}

unsigned int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw OnlyOneElementException(); 
    else 
    {
        sort(vec.begin(), vec.end());
        int span = vec.at(1) - vec.at(0);
        int span2;
        for(unsigned int i = 1; i < vec.size() ; i++)
        {
            span2 = vec.at(i) - vec.at(i - 1);
            if ( span2 < span)
                span = span2;  
        }
        return (span);
    }   
              
}

unsigned int Span::longestSpan()
{
    if (vec.size() < 2)
        throw OnlyOneElementException(); 
    else 
    {
        sort(vec.begin(), vec.end());
        return (vec.back() - vec.front());
    }          
}

template <class InputIterator>
void    Span::fill(InputIterator begin, InputIterator end)
{
    if (std::distance(begin, end) > _n)
        throw RangetoowideException();
    else
        vec.assign(begin, end);
      
}

void    Span::fill(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (std::distance(begin, end) > _n)
        throw RangetoowideException();
    else
        vec.assign(begin, end);        
}


void    Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) > _n)
        throw RangetoowideException();
    else
        vec.assign(begin, end);        
}


