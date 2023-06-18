/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:02:35 by amouly            #+#    #+#             */
/*   Updated: 2023/06/18 11:41:38 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

PhoneBook::PhoneBook(int number) : number(number) {
    std::cout << "your phone book is open";
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

void PhoneBook::add(void)
{
    if (this->number == 8)
        this->number = 0;
    std::stringstream ss;
    ss << this->number + 1 ;
    this->list[this->number].index = ss.str();

    std::cout << "Please type the first name of your contact : ";
    std::cin >> this->list[this->number].first_name;
    std::cout << "Please type the lastname of your contact : ";
    std::cin >> this->list[this->number].last_name;
    std::cout << "Please type the nickname of your contact : ";
    std::cin >> this->list[this->number].nickname;
    std::cout << "Please type the telephone number of your contact : ";
    std::cin >> this->list[this->number].num;
    std::cout << "Please type the darkest secret of your contact : ";
    std::cin >> this->list[this->number].secret;
    this->number++;
    
}
