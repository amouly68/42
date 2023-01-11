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

void a_to_b_v2(t_ps_list **list_a, t_ps_list **list_b, int grand, int median)
{
    
    if (grand == 1)
    {
        grand_to_top(list_a, median);
        pb(list_b, list_a);
    }
    else 
    {
        petit_to_top(list_a, median);
        pb(list_b, list_a);
    }
}