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

void display_empty_line()
{
    std::string line;
    line.assign(45, ' ');
    line.replace(0,1,1,'|');
    line.replace(11,1,1,'|');
    line.replace(22,1,1,'|');
    line.replace(33,1,1,'|');
    line.replace(44,1,1,'|');
    std::cout << line << std::endl;
    return ;
}

void display_empty_line()
{
    std::string line;
    line.assign(45, ' ');
    line.replace(,1,1,'|');
    line.replace(11,1,1,'|');
    line.replace(22,1,1,'|');
    line.replace(33,1,1,'|');
    line.replace(44,1,1,'|');
    std::cout << line << std::endl;
    return ;
}

void PhoneBook::display(void) const
{
    display_bordure();
    display_empty_line();
}