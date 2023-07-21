#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
public:
    
    Animal(void);
    Animal( Animal const & src );
    ~Animal();

    Animal & operator=( Animal const & rhs ); 

private:
    

};

#endif 
