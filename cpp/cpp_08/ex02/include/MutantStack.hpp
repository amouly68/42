#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack <T>
{


public:
    
    typedef typename std::deque<T>::iterator iterator;
    MutantStack() : std::stack<T> (){}
    MutantStack( MutantStack const & src ) : std::stack<T>(src){}

    ~MutantStack(){}

    typename std::deque<T>::iterator begin(){
        return (c.begin())
    }

    typename std::deque<T>::iterator end(){
        return (c.end());
    }

    

};

#endif 
