/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:17:11 by amouly            #+#    #+#             */
/*   Updated: 2023/06/21 11:07:16 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {

    public :
    
    
    PhoneBook();
    ~PhoneBook();
    void display(void) const; 
    void add(void);
    void search(void);
    
    private : 
    
    Contact _list[8]; 
    int     _number;

   
   
    
};

#endif