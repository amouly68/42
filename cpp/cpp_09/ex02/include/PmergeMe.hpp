#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <string>
#include <sys/time.h>
#include <list>


class PmergeMe {
public:
    
    PmergeMe(void);
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );
    void    add_numbers(double i);
    void    printVect();
    void    printDeque();
    void    printList();
    int     getVectSize();
    int     getDeqSize();
    int     getListSize();
    double  getTimeVec();
    double  getTimeDeque();
    double  getTimeList();
    void    SortAndCalculateTime(int n);
   

private:

    std::vector<int>    vec;
    std::list<int>      lis;
    std::list<int>      list_sorted;
    std::deque<int>     deq;
    double              time_vec;
    double              time_deq;
    double              time_lis;
    

};

#endif 
