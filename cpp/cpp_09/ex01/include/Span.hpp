#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

class Span {
public:
    
    Span(unsigned int n);
    Span( Span const & src );
    ~Span();

    Span &          operator=( Span const & rhs ); 
    void            addNumber(int n);
    unsigned int    shortestSpan(void);
    unsigned int    longestSpan(void);
    template <class InputIterator>
    void            fill(InputIterator begin, InputIterator end);
    void            fill(std::list<int>::iterator begin, std::list<int>::iterator end);
    void            fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
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

      class RangetoowideException : public std::exception
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
