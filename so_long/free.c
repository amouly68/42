/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:50:48 by amouly            #+#    #+#             */
/*   Updated: 2023/01/18 18:03:34 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_list(t_map **list)
{
	t_map	*next;

	next = NULL;
	if (list == NULL)
		return ;
	while (*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
}

void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free (tab[i]);
        i++;
    }
    free(tab);
}