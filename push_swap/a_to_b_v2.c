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

void a_to_b_v2(t_ps_list **list_a, t_ps_list **list_b)
{
    int nbr;
    int ind_min;
    int ind_max;
    int min;
    int max;
    int middle;
   // int i;

    nbr = count_pile(*list_a);
    ind_min = (index_min(*list_a));
    ind_max = (index_max(*list_a));
    min = find_min(*list_a)->nbr;
    max = find_max(*list_a)->nbr;
    middle = (max + min) / 2;
    ft_printf("nbr = %d\n", nbr);
    ft_printf("min = %d et ind_min : %d\n", min, ind_min);
    ft_printf("max = %d et ind_max : %d\n", max, ind_max);
    ft_printf("middle = %d\n", middle);
    pb(list_b, list_a);
    //i = 0;
    /*while (i < (nbr / 4))
    {
        grand_to_top(*list_a, middle, nbr);
        pb(list_b, list_a);
        i++;
    }
    while (i < (nbr / 4) * 3 )
    {
        petit_to_top(*list_a, middle, nbr);
        pb(list_b, list_a);
        i++;
    }
    while (i < (nbr))
    {
        grand_to_top(*list_a, middle, nbr);
        pb(list_b, list_a);
        i++;
    }*/
    
}

void grand_to_top(t_ps_list *list, int middle, int nbr)
{
    int index_rotate;
    int index_reverse;
    int i;

    index_rotate = 0;
    index_reverse = 0;
    i = 0;
    while(list)
    {
        if (list->nbr > middle)
            break ;
        index_rotate++;
        list = list -> next;
    }
    while(list)
    {
        if (list->nbr > middle)
            index_reverse = i;
        i++;
        list = list -> next;
    }
    if (index_rotate < (nbr - index_reverse))
    {
        while(index_rotate > 0)
        {
            ra(&list);
            index_rotate--;
        }
    } else 
    {
        while(index_reverse < nbr)
        {
            rra(&list);
            index_reverse++;
        }
    }
}

void petit_to_top(t_ps_list *list, int middle, int nbr)
{
    int index_rotate;
    int index_reverse;
    int i;

    index_rotate = 0;
    index_reverse = 0;
    i = 0;
    while(list)
    {
        if (list->nbr < middle)
            break ;
        index_rotate++;
        list = list -> next;
    }
    while(list)
    {
        if (list->nbr < middle)
            index_reverse = i;
        i++;
        list = list -> next;
    }
    if (index_rotate < (nbr - index_reverse))
    {
        while(index_rotate > 0)
        {
            ra(&list);
            index_rotate--;
        }
    } else
    {
        while(index_reverse < nbr)
        {
            rra(&list);
            index_reverse++;
        }
    }
}

