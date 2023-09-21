

#include "PmergeMe.hpp"



int main(int ac, char **av) 

{
    PmergeMe test;
    
    try
    {
        for (int i = 1; i < ac; i++)
        test.add_numbers(atof(av[i]));
        std::cout << "vecteur non trie : ";
        test.print_vect();
        test.fordJohnsonSort();
        std::cout << std::endl << "vecteur trie : ";
        test.print_vect();
        std::cout << "Time to sort a range of " << test.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test.getTimeVec() << " sec" << std::endl;
        
        std::cout << std::endl << "deque non trie : ";
        test.print_deque();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   



    return 0;
}

