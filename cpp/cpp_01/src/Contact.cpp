/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:02:35 by amouly            #+#    #+#             */
/*   Updated: 2023/06/19 09:38:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int Contact::add_first_name()
{
    std::string input;
    int i = 0;
    
    std::cout << "Please type the first name of your contact : " <<  std::endl;
    std::cin >> input;
    while(input.length() == 0 && i < 3)
    {
        std::cout << "You entered nothing, the first name of your contact :" << std::endl;
        std::cin >> input;
        i++;
    }
    if (input.length() == 0)
    {
        std::cout << "Sorry Contact adding failed, have another go" << std::endl;
        return (1);        
    }
    else
        this->first_name = input;
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