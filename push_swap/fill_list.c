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

int ft_addnode_back(t_ps_list **list, t_ps_list *new)
{
    t_ps_list   *temp;

    if(list == NULL && new == NULL)
        return (0);
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
        temp->next = new; 
    }
    return (1);
}

int fill_list(t_ps_list **list, int nbr)
{
    t_ps_list   *new;

    new = malloc(sizeof(t_ps_list));
    if (!new)
        return (0);
    new->nbr = nbr;
    new->next = NULL;
    if (!(ft_addnode_back(list, new)))
        return (0);
    return (1);
}

int fill_list_verif(t_ps_list **list, int argc, char **argv)
{
    int i;

    i = 1;
    while( i < argc)
    {
        if (!(fill_list(list, ft_atoi(argv[i]))))
            return (0);
        i++;
    }
    return (1);
}