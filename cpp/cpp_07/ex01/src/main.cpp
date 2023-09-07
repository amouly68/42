

#include "iter.hpp"
#include <iostream>
#include <array>

template <typename T, typename U >
U display(T obj)
{
    std::cout << "Display : " << obj << std::endl;
}


int main()
{
    int tab_int[] = {0,1,2,3,4,5,6};
    char tab_char[] = {'S','a','L','U','T'};
    std::array<std::string, 3>  tab_str = {"Chaine 1",
                                            "Chaine 2",
                                            "Phrase plus longue"}; 
    ::iter (tab_int, 7, &display);
    ::iter (tab_char, 7, &display);
    ::iter (tab_str, tab_str.size(), &display);

}