#include "../include/RPN.hpp"

#include <iostream>
#include <iomanip>

RPN::RPN(void) 
{
}

RPN::RPN(RPN const & src) 
{
    *this = src;
    return ;
}

RPN::~RPN() 
{
}

RPN &    RPN::operator=( RPN const & rhs ) 
{
    (void) rhs;
    return (*this);
}

void valid_char(std::string const &input)
{
    std::string::const_iterator it;
    for (it = input.begin(); it != input.end(); it++)
    {
        if (! (isdigit(*it) || isspace (*it) || *it == '+' || *it == '-' || *it == '/' || *it == '*'))
            throw std::runtime_error("Error : Input invalid");
    }
    return;
}

float calc(int a, int b, char c)
{
    if (c == '+')
        return (b + a);
    else if (c == '-')
        return (b - a);
    else if (c == '/')
    {
        return (static_cast<float>(b) / static_cast<float>(a));
    }    
    else
        return (b * a);
    
}
void fill_stack(std::stack<int> mystack, std::string input)
{
    std::string str;
    int a;
    int b;
    int digit = 0;
    int operand = 0;
    std::stringstream ss(input);
    float res = 0;

    while (getline(ss, str, ' '))
    {
        if (str.empty())
            continue;
        if (str.length() > 1 || (! (isdigit(str.at(0)) || isspace (str.at(0)) 
            || str.at(0) == '+' || str.at(0) == '-' || str.at(0) == '/' || str.at(0) == '*')))
            throw std::runtime_error("Error: input must be integer between 0 and 9");
        if (str.at(0) == '+' || str.at(0) == '-' || str.at(0) == '/' || str.at(0) == '*')
        {
            operand++;
            if (operand >= digit)
                throw std::runtime_error("Error: bad input");
            a = mystack.top();
            if (str.at(0) == '/' && a == 0)
                throw std::runtime_error("Error: division by 0");
            mystack.pop();
            b = mystack.top();
            mystack.pop();
            res = calc (a, b, str.at(0) );
            mystack.push(res);
        }    
        else  
        {
            mystack.push(str.at(0) - '0');
            digit++;
        }
    }
    std::cout << res << std::endl;
}

void    RPN::setInput( std::string input ) 
{

    try{
        valid_char (input);
        fill_stack(_mystack, input);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}

void    RPN::printStack() 
{
    while(!_mystack.empty())
    {
        char i = _mystack.top();
        std::cout << i << " ";
        _mystack.pop();
    }
     std::cout << std::endl;
}
