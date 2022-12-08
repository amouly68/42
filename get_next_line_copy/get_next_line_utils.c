/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/08 13:32:42 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(s_list **list, s_list *new)
{
	s_list *temp;

	if (new != NULL)
	{
		if ((*list) == NULL)
		{
			(*list) = new;
			new->next = NULL;
		}
		else
		{
			temp = (*list);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}

int newline_in_node(s_list *node)
{
	int	a;

	a = 0;
	if (node == NULL)
		return 0;
	while (node->str[a])
	{
		if (node->str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

