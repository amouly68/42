#include "../include/PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe(void) : time_vec(0), time_deq(0), time_lis(0)
{
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
    *this = src;
    return ;
}

PmergeMe::~PmergeMe() 
{
    
}

PmergeMe &    PmergeMe::operator=( PmergeMe const & rhs ) 
{
    (void) rhs;
    return (*this);
}

void    PmergeMe::add_numbers(double i)
{
    if (i < 0 || i > 2147483647 || ((i / i) != 1))
       throw std::runtime_error("Error : bad input. Numbers must positives integers ");
    //if ( std::find(vec.begin(), vec.end(), i) != vec.end() )
    //    throw std::runtime_error("Error : bad input. Cannot have duplicate ");
    vec.push_back(static_cast<int> (i));
    deq.push_back(static_cast<int> (i));
    lis.push_back(static_cast<int> (i));

}

void    PmergeMe::printVect()
{
    for(std::vector<int>::size_type i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDeque()
{
    for(std::deque<int>::size_type i = 0; i < deq.size(); i++)
        std::cout << deq.at(i) << " ";
    std::cout << std::endl;
}

void    PmergeMe::printList()
{
    std::list<int>::iterator it;
    for(it = lis.begin(); it != lis.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void mergeVec(std::vector<int>& vec, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

void insertVec(std::vector<int>& vec, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}



void MergeInsertVec(std::vector<int>& vec, int left, int right, int pack) 
{
    
    if (left < right) {
        int n = right - left + 1;

        if (n <= pack) {
            insertVec(vec, left, right);
        } else {
            int mid = left + (n - 1) / 2;
            MergeInsertVec(vec, left, mid, pack);
            MergeInsertVec(vec, mid + 1, right, pack);
            mergeVec(vec, left, mid, right);
        }
    }
}

void mergeDeq(std::deque<int>& deq, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> L(n1);
    std::deque<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = deq[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = deq[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deq[k] = L[i];
            ++i;
        } else {
            deq[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        deq[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        deq[k] = R[j];
        ++j;
        ++k;
    }
}

void insertDeq(std::deque<int>& deq, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
    {
        int key = deq[i];
        int j = i - 1;
        while (j >= left && deq[j] > key) {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

void MergeInsertDeq(std::deque<int>& deq, int left, int right) 
{
    
    if (left < right) {
        int n = right - left + 1;

        if (n <= 2) {
            insertDeq(deq, left, right);
        } else {
            int mid = left + (n - 1) / 2;
            MergeInsertDeq(deq, left, mid);
            MergeInsertDeq(deq, mid + 1, right);
            mergeDeq(deq, left, mid, right);
        }
    }
}


void insertionListSort(std::list<int>& lst) 
{
    std::list<int>::iterator it = lst.begin();
    ++it; 

    while (it != lst.end()) 
    {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;

        while (j != lst.begin() && *j > key) 
        {
            std::list<int>::iterator next_j = j;
            --next_j;
            *std::next(j) = *j;
            j = next_j;
        }

        *std::next(j) = key;
        ++it;
    }
}

void mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right) 
{
    std::list<int>::iterator leftit = left.begin();
    std::list<int>::iterator rightit = right.begin();
    std::list<int>::iterator listit = lst.begin();

    while (leftit != left.end() && rightit != right.end()) 
    {
        if (*leftit < *rightit) 
        {
            *listit = *leftit;
            ++leftit;
        } else 
        {
            *listit = *rightit;
            ++rightit;
        }
        ++listit;
    }

    while (leftit != left.end()) 
    {
        *listit = *leftit;
        ++leftit;
        ++listit;
    }

    while (rightit != right.end()) 
    {
        *listit = *rightit;
        ++rightit;
        ++listit;
    }
}

void mergeInsertList(std::list<int>& lis, int paquet) {
    int n = lis.size();

    if (n < 2)
        return;

    if (n < paquet) {
        insertionListSort(lis);
        return;
    }

    std::list<int>::iterator mid = lis.begin();
    std::advance(mid, n / 2);

    std::list<int> left(lis.begin(), mid);
    std::list<int> right(mid, lis.end());

    mergeInsertList(left, paquet);
    mergeInsertList(right, paquet);

    mergeList(lis, left, right);
}


void PmergeMe::SortAndCalculateTime(int n) 
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    mergeInsertList(lis, n);
    gettimeofday(&end, NULL);
    time_lis = (end.tv_sec - start.tv_sec) * 1e6;
    time_lis = (time_lis + (end.tv_usec - start.tv_usec)) * 1e-6;

    gettimeofday(&start, NULL);
    MergeInsertVec(vec,0, vec.size() - 1, n );
    gettimeofday(&end, NULL);
    time_vec = (end.tv_sec - start.tv_sec) * 1e6;
    time_vec = (time_vec + (end.tv_usec - start.tv_usec)) * 1e-6;


    /*gettimeofday(&start, NULL);
    MergeInsertDeq(deq,0, deq.size() - 1 );
    gettimeofday(&end, NULL);
    time_deq = (end.tv_sec - start.tv_sec) * 1e6;
    time_deq = (time_deq + (end.tv_usec - start.tv_usec)) * 1e-6;*/
    
}


int     PmergeMe::getVectSize() 
{
    return (vec.size());
}

int     PmergeMe::getDeqSize() 
{
    return (deq.size());
}

int     PmergeMe::getListSize() 
{
    return (lis.size());
}

double     PmergeMe::getTimeDeque() 
{
    return (time_deq);
}

double     PmergeMe::getTimeVec() 
{
    return (time_vec);
}

double     PmergeMe::getTimeList() 
{
    return (time_lis);
}