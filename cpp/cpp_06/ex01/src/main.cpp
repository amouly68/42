

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>




int main()
{
    Data test;
    test.c = 'a';
    test.i = 42;
    test.str = "YO";
    Data* ptr_data;

    uintptr_t yo;
    std::cout << "Adresse de test : " << &test << std::endl;
    yo = Serializer::serialize(&test);
    std::cout << "Apres serialize : " << yo << std::endl;
    ptr_data = Serializer::deserialize(yo);
    std::cout << "Apres deserialize : " << ptr_data << std::endl;

    std::cout << "-- Donnees de Test ----------    Donnees de Ptr_data" << std::endl;
    std::cout << test.c << " --------- " << ptr_data->c << std::endl;
    std::cout << test.str << " --------- " << ptr_data->str << std::endl;
    std::cout << test.i << " --------- " << ptr_data->i << std::endl;
}

