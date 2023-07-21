#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal {
public:
    
    WrongAnimal(void);
    WrongAnimal( WrongAnimal const & src );
    ~WrongAnimal();

    WrongAnimal & operator=( WrongAnimal const & rhs ); 

private:
    

};

#endif 
