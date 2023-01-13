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

int more_than_fifteen(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
    int i;
    
    i = 0;
    while (i < (argc - 1))
    {
        inf_borne_to_top(list_a, decile_1(*list_a));
        pb(list_b, list_a);
        i++;
    }
    while(*list_b)
    { 
        max_to_top_b(list_b);
        pa(list_a, list_b);
    }
    return (0);
}