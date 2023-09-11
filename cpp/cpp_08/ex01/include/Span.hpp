#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>

class Span {
public:
    
    Span(unsigned int n);
    Span( Span const & src );
    ~Span();

    Span & operator=( Span const & rhs ); 
    void addNumber(int n);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    class SpanIsFullException : public std::Exception
    {
        public : 
            virtual const char* what() const throw();
    };


private:
    Span(void);
    const unsigned int _n;
    std::list<int> li;
    

};

#endif 
