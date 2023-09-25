

#include "PmergeMe.hpp"



int main(int ac, char **av) 

{
    PmergeMe test2;
    // PmergeMe test5;
    // PmergeMe test10;
    // PmergeMe test20;
    
    try
    {
       
        for (int i = 1; i < ac; i++)
        {
            test2.add_numbers(atof(av[i]));
        //     test5.add_numbers(atof(av[i]));
        //     test10.add_numbers(atof(av[i]));
        //     test20.add_numbers(atof(av[i]));
         }
        std::cout << "vecteur non trie : ";
        test2.printVect();

        test2.SortAndCalculateTime(2);
        // test5.SortAndCalculateTime(5);
        // test10.SortAndCalculateTime(10);
        // test20.SortAndCalculateTime(20);
        
        std::cout << std::endl << "vecteur trie avec des paquets de 2  : ";
        test2.printVect();
        std::cout << "Time to sort a range of " << test2.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test2.getTimeVec() << " sec" << std::endl;

        std::cout << std::endl << "list triee avec des paquets de 2  : ";
        test2.printList();
        std::cout << "Time to sort a range of " << test2.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test2.getTimeList() << " sec" << std::endl;        

       /* std::cout << std::endl << "vecteur trie avec des paquets de 5  : ";
        //test5.printVect();
        std::cout << "Time to sort a range of " << test5.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test5.getTimeVec() << " sec" << std::endl;

        std::cout << std::endl << "vecteur trie avec des paquets de 10  : ";
        //test10.printVect();
        std::cout << "Time to sort a range of " << test10.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test10.getTimeVec() << " sec" << std::endl;

        std::cout << std::endl << "vecteur trie avec des paquets de 20  : ";
        //test20.printVect();
        std::cout << "Time to sort a range of " << test20.getVectSize() << " elements";
        std::cout << " with a vector is : " << std::fixed << std::setprecision(6) << test20.getTimeVec() << " sec" << std::endl;
        */
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   



    return 0;
}

