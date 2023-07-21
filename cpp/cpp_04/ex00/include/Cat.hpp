#ifndef CAT_HPP
#define CAT_HPP

class Cat {
public:
    
    Cat(void);
    Cat( Cat const & src );
    ~Cat();

    Cat & operator=( Cat const & rhs ); 

private:
    

};

#endif 
