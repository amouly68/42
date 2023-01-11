/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 11:52:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


int main(int argc, char **argv)
{
    t_ps_list *pile_a;
    t_ps_list *pile_b;
    

    pile_a = NULL;
    pile_b = NULL;
        
    if (!(fill_list_verif(&pile_a, argc, argv)))
      //clean la list en verifiant si pas nulle
      return(-1);

    if (argc < 5)
        less_than_four(&pile_a, argc - 1);
    if(argc > 4 && argc < 17 )
        four_to_fifteen(&pile_a, &pile_b, argc);  
    if (argc > 16)
    {
        more_than_fifteen_v2(&pile_a, &pile_b, argc, midd_value(pile_a)); 
       
        
    }

    
    //print_both_list(pile_a, pile_b);
    return (0);
}

