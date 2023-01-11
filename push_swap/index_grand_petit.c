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

int index_rot_grand(t_ps_list *list, int median)
{
    int index_rotate;

    index_rotate = 0;
    while(list)
    {
        if (list->nbr > median)
            break;
        index_rotate++;
        list = list->next;
    }
    return (index_rotate);
}

int index_rot_petit(t_ps_list *list, int median)
{
    int index_rotate;

    index_rotate = 0;
    while(list)
    {
        if (list->nbr < median)
            break;
        index_rotate++;
        list = list->next;
    }
    return (index_rotate);
}

int index_rev_grand(t_ps_list *list, int median)
{
    int index_rev;
    int i;

    index_rev = 0;
    i = 0;
    while(list)
    {
        if (list->nbr > median)
            index_rev = i;
        i++;
        list = list->next;
    } 
    return (index_rev);
}

int index_rev_petit(t_ps_list *list, int median)
{
    int index_rev;
    int i;

    index_rev = 0;
    i = 0;
    while(list)
    {
        if (list->nbr < median)
            index_rev = i;
        i++;
        list = list->next;
    } 
    return (index_rev);
}
