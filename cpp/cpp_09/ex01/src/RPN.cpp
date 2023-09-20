#include "../include/RPN.hpp"

#include <iostream>

RPN::RPN(void) 
{
    // TODO: Implémenter le constructeur
}

RPN::RPN(RPN const & src) 
{
    *this = src;
    return ;
}

RPN::~RPN() 
{
    // TODO: Implémenter le destructeur
}

RPN &    RPN::operator=( RPN const & rhs ) 
{
    (void) rhs;
    return (*this);
}

bool valid_char(std::string const &input)
{
    std::string::const_iterator it;
    for (it = input.begin(); it != input.end(); it++)
    {
        if (! (isdigit(*it) || isspace (*it) || *it == '+' || *it == '-' || *it == '/' || *it == '*'))
            return false;
    }
    return (true);
}

int calc(int a, int b, char c)
{
    if (c == '+')
        return (b + a);
    else if (c == '-')
        return (b - a);
    else if (c == '/')
        return (b / a);
    else
        return (b * a);
    
}
void fill_stack(std::stack<int> mystack, std::string input)
{
    std::string str;
    int a;
    int b;
    std::stringstream ss(input);
    int res = 0;

    while (getline(ss, str, ' '))
    {
        if (str.empty())
            continue;
        if (str.length() > 1 || (! (isdigit(str.at(0)) || isspace (str.at(0)) 
            || str.at(0) == '+' || str.at(0) == '-' || str.at(0) == '/' || str.at(0) == '*')))
        {
            std::cout << "Error: input must be between 0 and 10" << std::endl;
            return ;
        }
        if (str.at(0) == '+' || str.at(0) == '-' || str.at(0) == '/' || str.at(0) == '*')
        {
            a = mystack.top();
            mystack.pop();
            b = mystack.top();
            mystack.pop();
            std::cout << "a : " << a << " --- b : " << b << " ---- symbole : " << str.at(0) << std::endl;
            res = calc (a, b, str.at(0) );
            mystack.push(res);
        }    
        else 
        {   
            mystack.push(str.at(0) - '0');
            std::cout << str.at(0) - '0' << std::endl;
        }

    }
    std::cout << res << std::endl;
}

void    RPN::setInput( std::string input ) 
{

    if (valid_char (input))
        fill_stack(_mystack, input);
    else    
        std::cout << "Error : Input invalid" << std::endl;
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
