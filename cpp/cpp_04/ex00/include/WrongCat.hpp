#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat {
public:
    
    WrongCat(void);
    WrongCat( WrongCat const & src );
    ~WrongCat();

    WrongCat & operator=( WrongCat const & rhs ); 

private:
    

};

#endif 
