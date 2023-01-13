/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:15:18 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void clean_pile(t_ps_list **list_a)
{
    t_ps_list *next;

    next = NULL;
    if (list_a == NULL)
        return ;
    while (*list_a)
    {
        next = (*list_a)->next;
        free(*list_a);
        *list_a = next;
    }
  //  if ((*list_a) == NULL)
    //    free(list_a);
}

