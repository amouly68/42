#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    Array<int> test(10);
    std::cout << "la size de test est : " << test.size() << std::endl;
    for (unsigned int i = 0; i < test.size(); i++)
        test[i] = i;
    for (unsigned int j = 0; j < test.size(); j++)
        std::cout << "Test[" << j << "] = " << test[j] << std::endl;

    Array<int> test2(test);    
    for (unsigned int j = 0; j < test2.size(); j++)
        std::cout << "Test2[" << j << "] = " << test2[j] << std::endl;

    
    return(0);

}