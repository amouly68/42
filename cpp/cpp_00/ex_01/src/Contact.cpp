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

/* *****  ********    GETTERS ********* ******** ***/

std::string Contact::getIndex(void) const {
    return (this->_index);
}

std::string Contact::getFirst_name(void) const {
    return (this->_first_name);
}

std::string Contact::getLast_name(void) const {
    return (this->_last_name);
}

std::string Contact::getNickname(void) const {
    return (this->_nickname);
}

std::string Contact::getNum(void) const {
    return (this->_num);
}

std::string Contact::getSecret(void) const {
    return (this->_secret);
}

/* *****  ********    SETTERS ********* ******** ***/



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

void    Contact::setIndex(std::string input)
{
    this->_index = input;
    return ;
}


int Contact::setFirst_name(void)
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
        this->_first_name = input;
    return (0);
}

int Contact::setLast_name()
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
        this->_last_name = input;
    return (0);
}

int Contact::setNickname()
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
        this->_nickname = input;
    return (0);
}

int Contact::setNum()
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
        this->_num = input;
    return (0);
}

int Contact::setSecret()
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
        this->_secret = input;
    return (0);
}

void Contact::empty_contact(void)
{
    if (this->_first_name.length() != 0)
        this->_first_name.replace(0, this->_first_name.length(), this->_first_name.length(), ' ');
    if (this->_last_name.length() != 0)
        this->_last_name.replace(0, this->_last_name.length(), this->_last_name.length(), ' ');
    if (this->_nickname.length() != 0)
        this->_nickname.replace(0, this->_nickname.length(), this->_nickname.length(), ' ');
    if (this->_num.length() != 0)
        this->_num.replace(0, this->_num.length(), this->_num.length(), ' ');    
    if (this->_secret.length() != 0)
        this->_secret.replace(0, this->_secret.length(), this->_secret.length(), ' ');    
    
}

void Contact::display(void)
{
    std::cout << std::endl << "Here are your contact infos" << std::endl;
    std::cout << "First name : " << this->_first_name << std::endl;
    std::cout << "Last name : " << this->_last_name << std::endl;
    std::cout << "Nickname : " << this->_nickname << std::endl;
    std::cout << "Telephone Number : " << this->_num << std::endl;
    std::cout << "Darkest Secret : " << this->_secret << std::endl << std::endl ;
}