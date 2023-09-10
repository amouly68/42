#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>



class NotFoundException : public std::exception
{
        public : 
            virtual const char* what() const throw()
            {
                return ("No such element in this container");
            };
};

template <typename T>
int easyfind(T & a, const int b)
{
    typename T::iterator it;
    it = std::find(a.begin(), a.end(), b);
    if (it != a.end())
        std::cout << b << " is found !" << std::endl;
    else
        throw NotFoundException();
    return (*it);
}

#endif 
