#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

template <typename T>
class MutantStack {

private:

    std::deque<T> _data;

public:
    
    typedef typename std::deque<T>::iterator iterator;
    MutantStack(){};
    MutantStack( MutantStack const & src ){
        *this = src;
    }

    ~MutantStack(){};

    void push(const T &elem){
        _data.push_back(elem);
    }

    void pop(){
        _data.pop_front();
    }

    T& top(void){
        return (_data.back());
    };

    bool empty(){
        return(_data.empty());
    }

    unsigned int size(){
        return (_data.size());
    }

    typename std::deque<T>::iterator begin(){
        return (_data.begin());
    }

    typename std::deque<T>::iterator end(){
        return (_data.end());
    }

    

};

#endif 
