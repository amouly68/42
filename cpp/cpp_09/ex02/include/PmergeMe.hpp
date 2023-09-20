#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>


class PmergeMe {
public:
    
    PmergeMe(void);
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );
    void    add_vect(int i);
    void    print_vect();

private:
    std::vector<int> vec;

};

#endif 
