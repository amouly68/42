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
    
  
    void    setIndex(std::string input);
    int     setFirst_name(void);
    int     setLast_name(void);
    int     setNickname(void);
    int     setNum(void);
    int     setSecret(void);
    std::string getIndex(void) const;
    std::string getFirst_name(void) const;
    std::string getLast_name(void) const;
    std::string getNickname(void) const;
    std::string getNum(void) const;
    std::string getSecret(void) const;

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