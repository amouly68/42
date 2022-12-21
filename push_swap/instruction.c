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

t_ps_list   *ft_getlast(t_ps_list *list)
{
    if (!list)
        return (list);
    while (list->next)
        list = list->next;
    return (list);
}

t_ps_list   *ft_getprelast(t_ps_list *list)
{
    if (!list)
        return (list);
    while (list->next->next)
        list = list->next;
    return (list);
}

void    swap_pile(t_ps_list **list)
{
    t_ps_list *first;
    t_ps_list *second;
    t_ps_list *third;


    if (!list || !(*list) || !((*list)->next))
        return ;
    first = (*list)->next;
    second = *list;
    third = ((*list)->next)->next;
    *list = first;
    first->next = second;
    second->next = third;
}

void    push_x(t_ps_list **list_x, t_ps_list **list_y)
{
    t_ps_list   *first_x;
    t_ps_list   *second_x;
    t_ps_list   *first_y;


    if (!(list_y) || !(list_y) || !(*(list_y)))
        return ;
    first_x = *list_y;
    second_x = *list_x;
    first_y = (*list_y)->next;
    *list_x = first_x;
    first_x->next = second_x;
    *list_y = first_y;
}
void    rotate_pile(t_ps_list **list)
{
    t_ps_list *first;
    t_ps_list *prelast;
    t_ps_list *last;

    if ((!(list)) || (!(*list)) || (!((*list)->next)))
        return ;
    first = (*list)->next;
    prelast = ft_getlast(*list);
    last = *list;
    *list = first;
    prelast->next = last;
    last->next = NULL;
}

void    rev_rotate_pile(t_ps_list **list)
{
    t_ps_list *first;
    t_ps_list *second;
    t_ps_list *last;

    if ((!(list)) || (!(*list)) || (!((*list)->next)))
        return ;
    first = ft_getlast(*(list));
    second = *list;
    last = ft_getprelast(*list);
    *list = first;
    first->next = second;
    last->next = NULL;
}
