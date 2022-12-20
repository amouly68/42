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

void    ft_addnode_back(t_ps_list **list, t_ps_list *new)
{
    t_ps_list   *temp;

    if(list != NULL && new != NULL)
    {
    //while (*list)
      //  (*list) = (*list)->next; 
        if ((*list) == NULL)
        {
            (*list) = new;
            new->next = NULL;
        }
        else
        {
            temp = (*list);
            while(temp->next != NULL)
                temp = temp->next;
            (*list)->next = new; 
        }
    }
}

int fill_list(t_ps_list **list, int nbr)
{
    t_ps_list   *new;

    new = malloc(sizeof(t_ps_list));
    if (!new)
        return (-1);
    new->nbr = nbr;
    new->next = NULL;
    ft_addnode_back(list, new);
    return (0);
}

void print_list(t_ps_list *list)
{
    int i;

    i = 1;
    if (!list)
        return ;
    while (list)
    {
        ft_printf("noeud %d : %d\n", i, list->nbr);
        list = list->next;
        i++;
    }
}