/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/05 16:44:19 by amouly           ###   ########.fr       */
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

int	check_new_line(s_list *list, int *count)
{
	int i;

	if (list == NULL)
		return 0;
	while (list)
	{
		i = 0;
		while (list->str[i] != '\0')
		{
			if (list->str[i] == '\n')
			{
				(*count)++;
				return 1;
			}
			(*count)++;
			i++;
		}	
		list = list->next;
	}
	return 0;
}

char *extract_line(s_list *stock, int *count)
{
	int 	i;
	int		b;
	char	*ret;

	b = 0;
	if (stock == NULL)
		return NULL;
	ret = malloc (sizeof(char) * ((*count) + 1));
	if (ret == NULL)
		return (NULL);
	while (stock && b < *count)
	{
		i = 0;
		while (stock->str[i] != '\0' && stock->str[i] != '\n')
			ret[b++] = stock->str[i++];	
		if (stock->str[i] == '\n')
			ret[b] = '\n';
		stock = stock->next;
	}
	ret[*count] = '\0';
	return ret;
}

void trim_list(s_list **stock)
{
	s_list *temp;

	temp = *stock;
	while (*stock && (!(newline_in_node(*stock))))
	{
		temp = (*stock)->next;
		free ((*stock)->str);

		}		
	
	}



}


char	*get_next_line(int fd)
{
	static s_list *stock;
	int count;
	char *line;

	stock = NULL;
	count = 0;
	while (!(check_new_line(stock, &count)))
		fill_node(&stock, fd);
	line = extract_line(stock, &count);
	return (line);
}



