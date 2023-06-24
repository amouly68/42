/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:45:01 by amouly            #+#    #+#             */
/*   Updated: 2023/06/17 10:32:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i = 1;
    int j;
    if (ac > 1)
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
                std::cout << (char) toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    else 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    
}