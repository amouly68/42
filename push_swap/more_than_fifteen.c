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

int more_than_fifteen(t_ps_list **list_a, t_ps_list **list_b)
{
    
    while (*list_a)
        a_to_b(list_a, list_b);
    while (*list_b)
    { 
        max_to_top_b(list_b);
        pa(list_a, list_b);
    }
    return (0);
}

int more_than_fifteen_v2(t_ps_list **list_a, t_ps_list **list_b, int argc, int median)
{
    int i;

    i = 0;
    while (i < ((argc - 1) / 4))
    {
        a_to_b_v2(list_a, list_b, 1, median);
        i++;
    }
    while (i < ((argc - 1) / 2))
    {
        a_to_b_v2(list_a, list_b, 0, median);
        i++;
    }
     while (i < (argc - 1))
    {
        a_to_b_v2(list_a, list_b, 1, median);
        i++;
    }
    while(*list_b)
    { 
        max_to_top_b(list_b);
        pa(list_a, list_b);
    }
    return (0);
}

int more_than_fifteen_v3(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
    int i;

    i = 0;
    while (i < ((argc - 1) / 10) * 1)
    {
        a_to_b_bis(list_a, list_b, 1);
        i++;
    }
     while (i < ((argc - 1) / 10) * 2)
    {
        a_to_b_bis(list_a, list_b, 2);
        i++;
    }
     while (i < ((argc - 1) / 10) * 3)
    {
        a_to_b_bis(list_a, list_b, 3);
        i++;
    }
     while (i < ((argc - 1) / 10) * 4)
    {
        a_to_b_bis(list_a, list_b, 4);
        i++;
    }
     while (i < ((argc - 1) / 10) * 5)
    {
        a_to_b_bis(list_a, list_b, 5);
        i++;
    }
     while (i < ((argc - 1) / 10) * 6)
    {
        a_to_b_bis(list_a, list_b, 6);
        i++;
    }
     while (i < ((argc - 1) / 10) * 7)
    {
        a_to_b_bis(list_a, list_b, 7);
        i++;
    }
     while (i < ((argc - 1) / 10) * 8)
    {
        a_to_b_bis(list_a, list_b, 8);
        i++;
    }
     while (i < ((argc - 1) / 10) * 9)
    {
        a_to_b_bis(list_a, list_b, 9);
        i++;
    }
    while (i < (argc - 1))
    {
        a_to_b_bis(list_a, list_b, 10);
        i++;
    }
    while(*list_b)
    { 
        max_to_top_b(list_b);
        pa(list_a, list_b);
    }
    return (0);
}

