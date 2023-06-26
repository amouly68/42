/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:02:35 by amouly            #+#    #+#             */
/*   Updated: 2023/06/21 11:18:24 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* *****  ********    CONSTRUCTEUR ********* ******** ***/

PhoneBook::PhoneBook(void) {
    std::cout << "Hello, welcome to your phonebook !" << std::endl;
    std::cout << "You can add a new contact,"; 
    std::cout << " search an existing contact or exit the program : " << std::endl;
    std::cout << "Please type ADD, SEARCH or EXIT : "; 
    this->_number = 0;
    
}

/* *****  ********    DESTRUCTEUR ********* ******** ***/

PhoneBook::~PhoneBook(void) { 
}

/* *****  ********    DISPLAY ********* ******** ***/

void display_bordure()
{
    std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl ;
    return;
}

void trunc_and_replace(std::string *line, std::string str, int pos)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".|");
    }
    else
        str.append("|");
    line->replace(pos - str.length(), str.length(), str);
}


void display_line(std::string f_name, std::string name, std::string nickname, std::string secret )
{
    std::string line;
    line.assign(45, ' ');
    line.replace(0,1,1,'|');
    trunc_and_replace(&line, f_name, 12);
    trunc_and_replace(&line, name, 23);
    trunc_and_replace(&line, nickname, 34);
    trunc_and_replace(&line, secret, 45);
    std::cout << line << std::endl;
    return ;
}



void PhoneBook::display(void) const
{
    int i = -1;
    std::cout << std::endl;
    display_bordure();
    display_line("INDEX", "FIRST NAME", "NAME", "NICKNAME");
    display_bordure();
    while (++i < 8)
    {
        if (this->_list[i].getIndex().length() == 1)
            display_line(this->_list[i].getIndex(), this->_list[i].getFirst_name(), \
                            this->_list[i].getLast_name(), this->_list[i].getNickname());
        else
            display_line(" ", " ", " ", " ");
    }
    display_bordure();
    std::cout << std::endl;
}

/* *****  ********    ADD  ********* ******** ***/


void PhoneBook::add(void)
{
    std::string input;
    int index;
    std::stringstream ss;
    
    index = this->_number % 8;
     
    if (this->_list[index].setFirst_name() 
        || this->_list[index].setLast_name()
        || this->_list[index].setNickname() 
        || this->_list[index].setNum()
        || this->_list[index].setSecret())
        {
            this->_list[index].empty_contact();
            return;
        }
    ss << index + 1 ;
    this->_list[index].setIndex(ss.str());
    this->_number++;
    
    std::cout << std::endl << "THANK YOU  -  " << this->_list[index].getFirst_name();
    std::cout << " has been added to your phonebook !" << std::endl << std::endl;
    
    return ;
    
}


/* *****  ********    SEARCH  ********* ******** ***/

int    take_input(void)
{
    std::string input;
    std::stringstream ss;
    int i = 0;
    int index;
    
    std::cout << "Please type the index of your contact : " <<  std::endl;
    std::getline(std::cin, input);
    
    while((input.compare("1") && input.compare("2") &&
        input.compare("3") && input.compare("4") &&
        input.compare("5") && input.compare("6") &&
        input.compare("7") && input.compare("8"))  && i < 2)
    {
        std::cout << "Please enter a valid index:" << std::endl;
        std::getline(std::cin, input);
        i++;
    }
    ss << input;
    ss >> index;
    return (index);
    
}



void PhoneBook::search(void)
{
    int index;
    
    index = take_input();
    if (index < 1 || index > 8)
    {
        std::cout << "Sorry, search failed, have an other go" << std::endl;
        return ;
    }
    if (index > this->_number)
    {
        std::cout << "Sorry, no contact at this index, have an other go" << std::endl;
        return ;
    }
    else   
        this->_list[index - 1].display();
    return ;
    
}

