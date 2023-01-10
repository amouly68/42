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

t_ps_list *find_max(t_ps_list *list)
{
    t_ps_list   *ret;

    ret = list;
    while(list)
    {
        if (list->nbr > ret->nbr)
            ret = list;
        list = list->next;
    } 
    return (ret);
}

int index_max(t_ps_list *list)
{
    int index;
    int max;

    index = 0;
    max = (find_max(list)->nbr);
    while(list)
    {
        if (list->nbr == max)
            break ;
        index++;
        list = list -> next;
    } 
    return (index);
}


t_ps_list *find_min(t_ps_list *list)
{
    t_ps_list   *ret;

    ret = list;
    while(list)
    {
        if (list->nbr < ret->nbr)
            ret = list;
        list = list->next;
    } 
    return (ret);
}

int index_min(t_ps_list *list)
{
    int index;
    int min;

    index = 0;
    min = (find_min(list)->nbr);
    while(list)
    {
        if (list->nbr == min)
            break ;
        index++;
        list = list -> next;
    } 
    return (index);
}

/*int midd_value(t_ps_list *list)
{
    int nbr;
    int mid;
    int i;

    nbr = count_pile(list);
    i = 0;
    while (i < nbr / 2)
    {
        
    }


}*/