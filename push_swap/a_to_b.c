/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2022/12/20 09:50:55 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void a_to_b(t_ps_list **list_a, t_ps_list **list_b)
{
    int nbr;
    int ind_min;
    int ind_max;
    

    nbr = count_pile(*list_a);
    ind_min = (index_min(*list_a));
    ind_max = (index_max(*list_a));
   
    if(ind_min < ind_max && (nbr - ind_max) > ind_min)
    {
        min_to_top_a(list_a);
        pb(list_b, list_a);
    }
    else 
    {
        max_to_top_a(list_a);
        pb(list_b, list_a);
    }  
}


