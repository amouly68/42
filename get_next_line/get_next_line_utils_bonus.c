/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/14 11:12:33 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

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

int	newline_in_node(t_list *node)
{
	int	a;

	a = 0;
	if (node == NULL)
		return (0);
	while (node->str[a])
	{
		if (node->str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

int	check_new_line(t_list *list)
{
	int		i;
	t_list	*temp;

	if (list == NULL)
		return (0);
	temp = list;
	while (temp)
	{
		if (temp->str == NULL)
			return (0);
		i = 0;
		while (temp->str[i] != '\0')
		{
			if (temp->str[i] == '\n')
				return (1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

int	count_char_line(t_list *list)
{
	int	i;
	int	count;

	count = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i] != '\0')
		{
			if (list->str[i] == '\n')
			{
				count++;
				return (count);
			}
			count++;
			i++;
		}
		list = list->next;
	}
	return (count);
}

int	clean_stock(t_list **list, int fd, char *line)
{
	if (read(fd, line, 0) == -1)
	{
		trim_list(list);
		free(*list);
		(*list) = NULL;
		return (1);
	}
	else
		return (0);
}
