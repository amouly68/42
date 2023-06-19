/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:17:11 by amouly            #+#    #+#             */
/*   Updated: 2023/06/19 09:30:57 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact {

    public :
    
    std::string index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string num;
    std::string secret;
   // int         index;
    
    
   // Contact(std::string first_name, std::string last_name, 
     //       std::string nickname, std::string num, std::string secret);
   //~Contact(void);
    int   add_first_name();
    void  empty_contact(void) 
   
    
};

#endif