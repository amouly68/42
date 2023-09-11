#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class Span {
public:
    
    Span(unsigned int n);
    Span( Span const & src );
    ~Span();

    Span & operator=( Span const & rhs ); 
    void addNumber(int n);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    class SpanIsFullException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };

       class OnlyOneElementException : public std::exception
    {
        public : 
            virtual const char* what() const throw();
    };


private:
    Span(void);
    unsigned int _n;
    std::vector<int> vec;
    

};

#endif 
