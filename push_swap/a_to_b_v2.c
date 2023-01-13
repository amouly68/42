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

void a_to_b_v2(t_ps_list **list_a, t_ps_list **list_b, int grand)
{
    
    if (grand == 4)
        inf_borne_to_top(list_a, decile_1(*list_a));
    else if (grand == 3)
        sup_borne_to_top(list_a, prem_quarter(*list_a));
    else if (grand == 2)
        sup_borne_to_top(list_a, midd_value(*list_a));
    else if (grand == 1)
        sup_borne_to_top(list_a, third_quarter(*list_a));
    pb(list_b, list_a);
}

void a_to_b_bis(t_ps_list **list_a, t_ps_list **list_b, int quarter)
{
    
    if (quarter == 10)
        inf_borne_to_top(list_a, decile_1(*list_a));
    else if (quarter == 9)
        sup_borne_to_top(list_a, decile_1(*list_a));   
    else if (quarter == 8)
        sup_borne_to_top(list_a, decile_2(*list_a));
    else if (quarter == 7)
        sup_borne_to_top(list_a, decile_3(*list_a));
    else if (quarter == 6)
        sup_borne_to_top(list_a, decile_4(*list_a));   
    else if (quarter == 5)
        sup_borne_to_top(list_a, decile_5(*list_a));
    else if (quarter == 4)
        sup_borne_to_top(list_a, decile_6(*list_a));
    else if (quarter == 3)
        sup_borne_to_top(list_a, decile_7(*list_a));   
    else if (quarter == 2)
        sup_borne_to_top(list_a, decile_8(*list_a));
    else if (quarter == 1)
        sup_borne_to_top(list_a, decile_9(*list_a));    
            
    pb(list_b, list_a);
}