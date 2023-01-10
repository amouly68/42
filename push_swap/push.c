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

void    pa(t_ps_list **list_a, t_ps_list **list_b)
{
    t_ps_list   *first_a;
    t_ps_list   *second_a;
    t_ps_list   *first_b;


    if (!(list_a) || !(list_b) || !(*(list_b)))
        return ;
    first_a = *list_b;
    second_a = *list_a;
    first_b = (*list_b)->next;
    *list_a = first_a;
    first_a->next = second_a;
    *list_b = first_b;
    ft_printf("pa\n");
}

void    pb(t_ps_list **list_b, t_ps_list **list_a)
{
    t_ps_list   *first_b;
    t_ps_list   *second_b;
    t_ps_list   *first_a;


    if (!(list_b) || !(list_b) || !(*(list_a)))
        return ;
    first_b = *list_a;
    second_b = *list_b;
    first_a = (*list_a)->next;
    *list_b = first_b;
    first_b->next = second_b;
    *list_a = first_a;
    ft_printf("pb\n");
}

void    push_silent(t_ps_list **list_a, t_ps_list **list_b)
{
    t_ps_list   *first_a;
    t_ps_list   *second_a;
    t_ps_list   *first_b;


    if (!(list_a) || !(list_b) || !(*(list_b)))
        return ;
    first_a = *list_b;
    second_a = *list_a;
    first_b = (*list_b)->next;
    *list_a = first_a;
    first_a->next = second_a;
    *list_b = first_b;
}

