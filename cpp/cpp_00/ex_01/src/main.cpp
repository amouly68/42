/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:45:01 by amouly            #+#    #+#             */
/*   Updated: 2023/06/21 11:23:42 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdlib.h>

int main()
{
    std::string input;
    PhoneBook repertoire;

    
    while (1)
    {
        std::cin.clear();
        std::getline(std::cin, input);
        if(input.compare("ADD") == 0)
            repertoire.add();
        else if(input.compare("SEARCH") == 0)
        {
            repertoire.display();
            repertoire.search();
        }
        else if(input.compare("EXIT") == 0)
        {
            std::cout << "Thank you, Bye !" << std::endl;
            break;
        }
        else 
            std::cout << "I didn't understand, sorry..." << std::endl; 
        std::cout << "Please type ADD, SEARCH or EXIT : "; 
    }   
    return (0);
}