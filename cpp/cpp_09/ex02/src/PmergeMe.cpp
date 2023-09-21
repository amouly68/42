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

void    PmergeMe::add_vect(int i)
{
    vec.push_back(i);
}

void    PmergeMe::print_vect()
{
    std::cout << "Before :   ";
    for(std::vector<int>::size_type i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ";
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


void PmergeMe::fordJohnsonSort(std::vector<int>& vec, int left, int right) 
{
    
    if (left < right) {
        int n = right - left + 1;

        if (n <= 2) {
            insertionSort(vec, left, right);
        } else {
            int mid = left + (n - 1) / 2;
            fordJohnsonSort(vec, left, mid);
            fordJohnsonSort(vec, mid + 1, right);
            merge(vec, left, mid, right);
        }
    }
}

int     PmergeMe::getVectSize() 
{
    return (vec.size());
}
