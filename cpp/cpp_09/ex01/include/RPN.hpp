#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <stack>
#include <cctype>
#include <sstream>


class RPN {
public:
    
    RPN(void);
    RPN( RPN const & src );
    ~RPN();

    RPN & operator=( RPN const & rhs ); 
    void    setInput(std::string);
    void    printStack();

private:
    std::stack<int> _mystack;
    std::string     _input;

};

#endif 
