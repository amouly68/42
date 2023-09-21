

#include "PmergeMe.hpp"



int main(int ac, char **av) 

{
    PmergeMe test;
    
    try
    {
       
        for (int i = 1; i < ac; i++)
            test.add_numbers(atof(av[i]));
        std::cout << "vecteur non trie : ";
        test.printVect();


        std::cout << "list non triee : ";
        test.printList();
        std::cout << "taille de la liste " << test.getListSize() << std::endl;
        test.SortAndCalculateTime();

        std::cout << std::endl << "vecteur trie : ";
        test.printVect();
        std::cout << "Time to sort a range of " << test.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test.getTimeVec() << " sec" << std::endl;
        

        std::cout << std::endl << "List triee : ";
        test.printList();
        std::cout << "Time to sort a range of " << test.getListSize() << " elements";
        std::cout << " with a list is : " << std::fixed << std::setprecision(6) << test.getTimeList() << " sec" << std::endl;

        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   



    return 0;
}

