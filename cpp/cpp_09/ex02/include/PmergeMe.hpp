#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <string>
#include <sys/time.h>


class PmergeMe {
public:
    
    PmergeMe(void);
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );
    void    add_numbers(double i);
    void    print_vect();
    void    print_deque();
    int     getVectSize();
    double  getTimeVec();
    double  getTimeDeque();
    void    fordJohnsonSort();
   

private:

    std::vector<int> vec;
    std::vector<int> vec_copy;
    std::deque<int> deq;
    double          time_vec;
    double          time_deque;
    

};

#endif 
