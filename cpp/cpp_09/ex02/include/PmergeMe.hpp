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
    int     getVectSize();
    void    fordJohnsonSort(std::vector<int>& vec, int left, int right);
    std::vector<int> vec;
    std::vector<int> vec_copy;

private:
    

};

#endif 
