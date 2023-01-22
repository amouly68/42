/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:50:48 by amouly            #+#    #+#             */
/*   Updated: 2023/01/21 12:40:23 by amouly           ###   ########.fr       */
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
		free((*list)->line);
		free(*list);
		(*list) = next;
	}
}