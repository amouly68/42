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

void sort_three_numbers_a(t_ps_list **list_a)
{
    int top;
    int middle;
    int bottom;

    top = (*list_a)->nbr;
    middle = (*list_a)->next->nbr;
    bottom = (*list_a)->next->next->nbr;
    if (top < middle && middle < bottom)
        return ;
    else if (bottom > top && top > middle )
        sa(list_a);
    else if ( top > bottom  && bottom > middle )
        ra(list_a);
    else if (middle > top && top > bottom )
        rra(list_a);
    else if (bottom < middle  && middle < top )
    {
        sa(list_a);
        rra(list_a);
    }
    else if (middle > bottom && bottom > top )
    {
        sa(list_a);
        ra(list_a);
    }
}

void sort_three_numbers_inv_a(t_ps_list **list_a)
{
    int top;
    int middle;
    int bottom;

    top = (*list_a)->nbr;
    middle = (*list_a)->next->nbr;
    bottom = (*list_a)->next->next->nbr;
    if (top > middle && middle > bottom)
        return ;
    else if (bottom < top && top < middle )
        sa(list_a);
    else if ( top < bottom  && bottom < middle )
        ra(list_a);
    else if (middle < top && top < bottom )
        rra(list_a);
    else if (bottom > middle  && middle > top )
    {
        sa(list_a);
        rra(list_a);
    }
    else if (middle < bottom && bottom < top )
    {
        sa(list_a);
        ra(list_a);
    }
}

void less_than_four(t_ps_list **list_a, int num)
{
    if(num == 1)
        return ;
    if(num == 2)
    {
        if ((*list_a)->nbr > (*list_a)->next->nbr)
        {
            sa(list_a);
            return ;
        }
    }
    if(num == 3)
    {
        sort_three_numbers_a(list_a);
        return ;
    }
}


int four_to_fifteen(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
    int i;

    i = 4;
    while(i < argc)
    {
        min_to_top_a(list_a);
        pb(list_b, list_a); 
        i++;
    }
    sort_three_numbers_a(list_a);
    while(*list_b)
        pa(list_a, list_b);
    print_both_list(*list_a, *list_b);
    /*
    print_both_list(*list_a, *list_b);
  
    
    return(1);*/
    return (0);
}

