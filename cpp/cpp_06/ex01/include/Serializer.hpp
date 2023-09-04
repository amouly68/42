#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <string>
#include <iomanip>

class Serializer {
public:
    
    Serializer(void);
    Serializer( Serializer const & src );
    ~Serializer();

    Serializer & operator=( Serializer const & rhs ); 
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    

};

#endif 
