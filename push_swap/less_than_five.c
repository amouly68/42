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

void sort_three_numbers(t_ps_list **list_a)
{
    int top;
    int middle;
    int bottom;

    top = (*list_a)->nbr;
    middle = (*list_a)->next->nbr;
    bottom = (*list_a)->next->next->nbr;
    if (top < middle && middle < bottom)
        return ;
    if (bottom > top && top > middle )
        sa;
    else if ( top > bottom  && bottom > middle )
        ra;
    else if (middle > top && top > bottom )
        rra;
    else if (bottom < middle  && middle < top )
    {
        sa;
        rra;
    }
    else if (middle > bottom && bottom > top )
    {
        sa;
        ra;
    }
}


int less_than_three(t_ps_list **list_a, int argc)
{
    if(argc == 3)
    {
        if ((*list_a)->nbr > (*list_a)->next->nbr)
        {
            sa(list_a);
            return(1);
        }
    }
    if(argc == 4)
    {
        sort_three_numbers(list_a);
        return(1);
    }
    return (0);
}


int three_to_five(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
    int i;

    i = 0;
    if (argc == 5)
    {
        pb; 
        sort_three_numbers(list_a);
        while(((*list_b)->nbr) < (*list_a)->next->next->nbr)
        {
            rra;
            i++;
        }
        pa;
        while (i > -1)
            ra;
    }


}

