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
    ft_printf("----FIN DE LA LISTE----\n");
}

void print_both_list(t_ps_list *list_1, t_ps_list *list_2)
{
    int i;

    i = 1;
    if ((!list_1) && (!list_2))
        return ;
    ft_printf("---PILE A----|----PILE B----\n", i, list_1->nbr);
    while (list_1 && list_2)
    {
        ft_printf("noeud %d : %d  | noeud %d : %d   \n", i, list_1->nbr, i, list_2->nbr);
        list_1 = list_1->next;
        list_2 = list_2->next;
        i++;
    }
    if (list_1 == NULL)
    {
        while (list_2)
        {
            ft_printf("----FINI-----| noeud %d : %d   \n", i, list_2->nbr);
            list_2 = list_2->next;
            i++;
        }
    }
    if (list_2 == NULL)
    {
        while (list_1)
        {
            ft_printf("noeud %d : %d  |-------FINI------\n", i, list_1->nbr);
            list_1 = list_1->next;
            i++;
        }
    }
    ft_printf("----FIN DES LISTES----\n");
}

