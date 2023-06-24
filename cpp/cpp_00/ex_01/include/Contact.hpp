/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:17:11 by amouly            #+#    #+#             */
/*   Updated: 2023/06/21 11:27:48 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact {

    public :
    
    Contact(void);
    ~Contact(void);
    
    std::string index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string num;
    std::string secret;
  
    int   add_first_name(void);
    int   add_last_name(void);
    int   add_nickname(void);
    int   add_num(void);
    int   add_secret(void);
    void  empty_contact(void);
    void  display(void);
   
   private : 

    std::string _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _num;
    std::string _secret;
    
};

#endif