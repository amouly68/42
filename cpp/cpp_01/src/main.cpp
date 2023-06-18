/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:45:01 by amouly            #+#    #+#             */
/*   Updated: 2023/06/18 11:07:27 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string input;
    Contact new_contact;
    PhoneBook the_one;
    
    std::cout << "Hello, welcome to your phonebook !" << std::endl;
    std::cout << "You can add a new contact,"; 
    std::cout << " search an existing contact or to exit the program : " << std::endl;
    std::cout << "Please type ADD, SEARCH or EXIT : "; 
    while (1)
    {
        std::cin>> input;
        if(input.compare("ADD") == 0)
            std::cout << "You want to add" << std::endl;
        else if(input.compare("SEARCH") == 0)
        {
            std::cout << "You want to search" << std::endl;
            the_one.display();
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