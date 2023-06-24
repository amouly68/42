/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:02:35 by amouly            #+#    #+#             */
/*   Updated: 2023/06/21 11:04:30 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* *****  ********    CONSTRUCTEUR ********* ******** ***/

Contact::Contact(void) {  
}

/* *****  ********    DESTRUCTEUR ********* ******** ***/

Contact::~Contact(void) { 
}



int string_is_not_valid(std::string input, int dig_or_let)
{
    int i = 0;
    if ((int)input.length() == 0)
        return (1);
    if (dig_or_let == 1)
    {
        while(i < (int)input.length())
        {
            if (!isalpha(input.at(i)) )
               return (1);
            i++; 
        }
    }
    else
    {
        while(i < (int)input.length())
        {
            if (!isdigit(input.at(i)))
               return (1);
            i++; 
        }
    }
    return (0);
}


int Contact::add_first_name()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type the first name of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while(string_is_not_valid(input, 1) && i < 2)
    {
        std::cout << "!!!! WRONG !!!!!!" << std::endl;
        std::cout << "Please enter a valid first name (only letters) :" << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    if (string_is_not_valid(input, 1))
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->first_name = input;
    return (0);
}

int Contact::add_last_name()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type the last name of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while(string_is_not_valid(input, 1) && i < 2)
    {
        std::cout << "!!!! WRONG !!!!!!" << std::endl;
        std::cout << "Please enter a valid last name (only letters) :" << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    if (string_is_not_valid(input, 1))
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->last_name = input;
    return (0);
}

int Contact::add_nickname()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type the nickname of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while(string_is_not_valid(input, 1) && i < 2)
    {
        std::cout << "!!!! WRONG !!!!!!" << std::endl;
        std::cout << "Please enter a valid nickname (only letters) :" << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    if (string_is_not_valid(input, 1))
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->nickname = input;
    return (0);
}

int Contact::add_num()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type telephone number of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while(string_is_not_valid(input, 2) && i < 2)
    {
        std::cout << "!!!! WRONG !!!!!!" << std::endl;
        std::cout << "Please enter a valid phone number (only digit) : " << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    if (string_is_not_valid(input, 2))
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->num = input;
    return (0);
}

int Contact::add_secret()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type the darkest secret of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while(string_is_not_valid(input, 1) && i < 2)
    {
        std::cout << "!!!! WRONG !!!!!!" << std::endl;
        std::cout << "Please enter a valid secret (only letters) : " << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    if (string_is_not_valid(input, 1))
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->secret = input;
    return (0);
}

void Contact::empty_contact(void)
{
    if (this->first_name.length() != 0)
        this->first_name.replace(0, this->first_name.length(), this->first_name.length(), ' ');
    if (this-last_name.length() != 0)
        this->last_name.replace(0, this->last_name.length(), this->last_name.length(), ' ');
    if (this->nickname.length() != 0)
        this->nickname.replace(0, this->nickname.length(), this->nickname.length(), ' ');
    if (this->num.length() != 0)
        this->num.replace(0, this->num.length(), this->num.length(), ' ');    
    if (this->secret.length() != 0)
        this->secret.replace(0, this->secret.length(), this->secret.length(), ' ');    
    
}

void Contact::display(void)
{
    std::cout << std::endl << "Here are your contact infos" << std::endl;
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Telephone Number : " << this->num << std::endl;
    std::cout << "Darkest Secret : " << this->secret << std::endl << std::endl ;
}