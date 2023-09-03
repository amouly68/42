#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
    
    Brain(void);
    Brain( Brain const & src );
    ~Brain();

    Brain & operator=( Brain const & rhs ); 

    std::string getIdeas(int indice);

private:

    std::string _ideas [100];

};

#endif 
