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
#include <stdlib.h>

void add(PhoneBook *the_one)
{
    if (the_one->number == 8)
        the_one->number = 0;
    std::stringstream ss;
    ss << the_one->number + 1 ;
    the_one->list[the_one->number].index = ss.str();

    std::cout << "Please type the first name of your contact : ";
    std::cin >> the_one->list[the_one->number].first_name;
    std::cout << "Please type the lastname of your contact : ";
    std::cin >> the_one->list[the_one->number].last_name;
    std::cout << "Please type the nickname of your contact : ";
    std::cin >> the_one->list[the_one->number].nickname;
    std::cout << "Please type the telephone number of your contact : ";
    std::cin >> the_one->list[the_one->number].num;
    std::cout << "Please type the darkest secret of your contact : ";
    std::cin >> the_one->list[the_one->number].secret;
    the_one->number++;
    
}



int main()
{
    std::string input;
    PhoneBook repertoire(0);
    
    std::cout << "Hello, welcome to your phonebook !" << std::endl;
    std::cout << "You can add a new contact,"; 
    std::cout << " search an existing contact or exit the program : " << std::endl;
    std::cout << "Please type ADD, SEARCH or EXIT : "; 
    while (1)
    {
        std::cin>> input;
        if(input.compare("ADD") == 0)
            repertoire.add();
        else if(input.compare("SEARCH") == 0)
        {
            std::cout << "You want to search" << std::endl;
            repertoire.display();
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