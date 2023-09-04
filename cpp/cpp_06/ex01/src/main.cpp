

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>




int main()
{
    Data test;
    Data* ptr_data;

    uintptr_t yo;
    std::cout << "ADresse de test " << &test << std::endl;
    yo = Serializer::serialize(&test);
    std::cout << "Apres serialize " << yo << std::endl;
    ptr_data = Serializer::deserialize(yo);
    std::cout << "Apres deserialize " << ptr_data << std::endl;
}