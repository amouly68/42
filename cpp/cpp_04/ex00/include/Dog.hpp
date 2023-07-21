#ifndef DOG_HPP
#define DOG_HPP

class Dog {
public:
    
    Dog(void);
    Dog( Dog const & src );
    ~Dog();

    Dog & operator=( Dog const & rhs ); 

private:
    

};

#endif 
