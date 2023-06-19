/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:02:35 by amouly            #+#    #+#             */
/*   Updated: 2023/06/19 12:55:05 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* *****  ********    CONSTRUCTEUR ********* ******** ***/

PhoneBook::PhoneBook(int number) : number(number) {
    std::cout << "Hello, welcome to your phonebook !" << std::endl;
    std::cout << "You can add a new contact,"; 
    std::cout << " search an existing contact or exit the program : " << std::endl;
    std::cout << "Please type ADD, SEARCH or EXIT : "; 
    
}

/* *****  ********    DISPLAY ********* ******** ***/

void display_bordure()
{
    std::string line;
    line.assign(45, '-');
    std::cout << line << std::endl;
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
    display_bordure();
    display_line("INDEX", "FIRST NAME", "NAME", "NICKNAME");
    display_bordure();
    while (++i < 8)
    {
        if (this->list[i].index.length() == 1)
            display_line(this->list[i].index, this->list[i].first_name, \
                            this->list[i].last_name, this->list[i].nickname);
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
    
    index = this->number % 8;
     
    if (this->list[index].add_first_name() 
        || this->list[index].add_last_name()
        || this->list[index].add_nickname() 
        || this->list[index].add_num()
        || this->list[index].add_secret())
        {
            this->list[index].empty_contact();
            return;
        }
    ss << index + 1 ;
    this->list[index].index = ss.str();
    this->number++;
    
    std::cout << std::endl << "THANK YOU  -  " << this->list[index].first_name;
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
    std::cin >> input;
    
    while((input.compare("1") && input.compare("2") &&
        input.compare("3") && input.compare("4") &&
        input.compare("5") && input.compare("6") &&
        input.compare("7") && input.compare("8"))  && i < 2)
    {
        std::cout << "Please enter a valid index:" << std::endl;
        std::cin >> input;
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
    if (index > this->number)
    {
        std::cout << "Sorry, no contact at this index, have an other go" << std::endl;
        return ;
    }
    else   
        this->list[index - 1].display();
    return ;
    
}

