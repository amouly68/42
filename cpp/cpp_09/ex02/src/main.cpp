

#include "MutantStack.hpp"
#include <stack>
#include <iostream>


int main() {
    MutantStack<int> stack_perso;

    
    stack_perso.push(1);
    stack_perso.push(2);
    stack_perso.push(3);
    stack_perso.pop();

    MutantStack<int>::iterator it = stack_perso.begin();
    MutantStack<int>::iterator itEnd = stack_perso.end();

    while (it != itEnd) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;


     std::stack<int> stack_true;

    
    stack_true.push(1);
    stack_true.push(2);
    stack_true.push(3);
    stack_true.pop();

    std::cout << stack_true.top() << " " << std::endl;




    return 0;
}

