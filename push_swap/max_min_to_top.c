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

int count_pile(t_ps_list    *list)
{
    int nbr;

    nbr = 0;
    while(list)
    {
        nbr++;
        list = list->next;
    }
    return (nbr);
}

void max_to_top_a(t_ps_list **list)
{
    int nbr;
    int ind_max;

    nbr = count_pile(*list);
    ind_max = (index_max(*list)); 
    if (ind_max <= (nbr / 2))
    {
        while (ind_max > 0)
        {
            ra(list);
            ind_max--;
        }
    }
    else if (ind_max > (nbr / 2))
    {
        while (ind_max < nbr)
        {
            rra(list);
            ind_max++;
        }
    }
}

void min_to_top_a(t_ps_list **list)
{
    int nbr;
    int ind_min;

    nbr = count_pile(*list);
    ind_min = (index_min(*list)); 
    if (ind_min <= (nbr / 2))
    {
        while (ind_min > 0)
        {
            ra(list);
            ind_min--;
        }
    }
    else if (ind_min > (nbr / 2))
    {
        while (ind_min < nbr)
        {
            rra(list);
            ind_min++;
        }
    }
}

void max_to_top_b(t_ps_list **list)
{
    int nbr;
    int ind_max;

    nbr = count_pile(*list);
    ind_max = (index_max(*list)); 
    if (ind_max <= (nbr / 2))
    {
        while (ind_max > 0)
        {
            rb(list);
            ind_max--;
        }
    }
    else if (ind_max > (nbr / 2))
    {
        while (ind_max < nbr)
        {
            rrb(list);
            ind_max++;
        }
    }
}


