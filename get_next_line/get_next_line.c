/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/05 12:57:27 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(s_list **list, s_list *new)
{
	s_list *temp;

	if (new != NULL && list != NULL)
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

void fill_node(s_list **stock, int fd)
{
	s_list *new;
	s_list *last;

	new = malloc(sizeof(s_list));
	if (new == NULL)
		return ;
	ft_lstadd_back(stock, new);
	new->str = malloc ((sizeof(char) * BUFFER_SIZE) + 1);
	if (new->str == NULL)
		return ;
	read(fd, new->str, BUFFER_SIZE);
	new->str[BUFFER_SIZE] = '\0';
}




char	*get_next_line(int fd)
{
	static s_list *stock;
	char	*return_val;

	stock = NULL;
	fill_node(&stock, fd);		
}



