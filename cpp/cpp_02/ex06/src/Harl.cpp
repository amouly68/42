#include "../include/Harl.hpp"


Harl::Harl() 
{
    _PtrFunct[0] = &Harl::_debug;
    _PtrFunct[1] = &Harl::_info;
    _PtrFunct[2] = &Harl::_warning;
    _PtrFunct[3] = &Harl::_error;
    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";
}

Harl::~Harl() 
{
    
}

void    Harl::_debug(void){
    std::cout << "DEBUG : Message" << std::endl;
}

void    Harl::_info(void){
    std::cout << "INFO : Message" << std::endl;
}

void    Harl::_warning(void){
    std::cout << "WARNING : Message" << std::endl;
}

void    Harl::_error(void){
    std::cout << "ERROR : Message" << std::endl;
}

void    Harl::complain(std::string level) {
    int i = 0;
    while (i < 4)
    {
        if (level.compare(this->_levels[i]) == 0)
            break;
        i++;
    }
    switch (i)
    {
    case 0 :
        (this->*_PtrFunct[0])();
        (this->*_PtrFunct[1])();
        (this->*_PtrFunct[2])();
        (this->*_PtrFunct[3])();
        break;
    
    case 1 :
        (this->*_PtrFunct[1])();
        (this->*_PtrFunct[2])();
        (this->*_PtrFunct[3])();
        break;
    
    case 2 :
        (this->*_PtrFunct[2])();
        (this->*_PtrFunct[3])();
        break;

    case 3 :
        (this->*_PtrFunct[3])();
        break;
    
    default:
        std::cout << "wrong filter" << std::endl;
        break;
    }
}
