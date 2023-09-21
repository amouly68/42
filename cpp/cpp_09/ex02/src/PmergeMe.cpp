#include "../include/PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe(void) 
{
    // TODO: Implémenter le constructeur
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
    *this = src;
    return ;
}

PmergeMe::~PmergeMe() 
{
    // TODO: Implémenter le destructeur
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
     //   throw std::runtime_error("Error : bad input. Cannot have duplicate ");
    vec.push_back(static_cast<int> (i));
    deq.push_back(static_cast<int> (i));

}

void    PmergeMe::print_vect()
{
    for(std::vector<int>::size_type i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ";
    std::cout << std::endl;
}

void    PmergeMe::print_deque()
{
    for(std::deque<int>::size_type i = 0; i < deq.size(); i++)
        std::cout << deq.at(i) << " ";
    std::cout << std::endl;
}

void merge(std::vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void insertionSort(std::vector<int>& arr, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


void InsertSort_vec(std::vector<int>& vec, int left, int right) 
{
    
    if (left < right) {
        int n = right - left + 1;

        if (n <= 2) {
            insertionSort(vec, left, right);
        } else {
            int mid = left + (n - 1) / 2;
            InsertSort_vec(vec, left, mid);
            InsertSort_vec(vec, mid + 1, right);
            merge(vec, left, mid, right);
        }
    }
}

void PmergeMe::fordJohnsonSort() 
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    InsertSort_vec(vec,0, vec.size() - 1 );
    gettimeofday(&end, NULL);
    time_vec = (end.tv_sec - start.tv_sec) * 1e6;
    time_vec = (time_vec + (end.tv_usec - start.tv_usec)) * 1e-6;
}


int     PmergeMe::getVectSize() 
{
    return (vec.size());
}

double     PmergeMe::getTimeDeque() 
{
    return (time_deque);
}

double     PmergeMe::getTimeVec() 
{
    return (time_vec);
}