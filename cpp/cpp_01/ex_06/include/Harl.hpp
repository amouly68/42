#ifndef HARL_HPP
#define HARL_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include <stdlib.h>



class Harl {
public:
    
    Harl();
    ~Harl();

    void    complain(std::string level);
   

private:
    void    _debug(void);
    void    _info(void);
    void    _warning(void);
    void    _error(void);

    typedef void (Harl::*PtrFunc)();
    PtrFunc _PtrFunct[4];
    std::string _levels[4];

};


#endif 
