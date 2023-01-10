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

int more_than_fifteen(t_ps_list **list_a, t_ps_list **list_b)
{
    //a_to_b_v2(list_a, list_b); 
   while(*list_a)
        a_to_b(list_a, list_b);
    while(*list_b)
    { 
        max_to_top_b(list_b);
        pa(list_a, list_b);
    }
    return (0);
}

