/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/06 12:29:00 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int fill_node(s_list **stock, int fd)
{
	s_list *new;
	s_list *last;

	new = malloc(sizeof(s_list));
	if (new == NULL)
		return 0;
	ft_lstadd_back(stock, new);
	new->str = malloc ((sizeof(char) * BUFFER_SIZE) + 1);
	if (new->str == NULL)
		return 0;
	if (read(fd, new->str, BUFFER_SIZE) <= 0)
		return 0;
	new->str[BUFFER_SIZE] = '\0';
	return 1;
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

void	trim_str(char **str)
{
	
	while (**str != '\n')
		(*str)++;
	if (**str == '\n')
		(*str)++;
}

void trim_list(s_list **stock)
{
	s_list *temp;

	if (*stock == NULL || stock == NULL)
		return ;
	while (*stock && (!(newline_in_node(*stock))))
	{
		temp = *stock;
		*stock = (*stock)->next;
		free ((temp)->str);
		free (temp);
	}		
	if (newline_in_node(*stock))
		//trim_str((*stock)->str);
}


/*char	*get_next_line(int fd)
{
	static s_list *stock;
	int count;
	char *line;

	stock = NULL;
	count = tri;
	while (!(check_new_line(stock, &count)))
	{
		if (!(fill_node(&stock, fd)))
			return NULL;
	}
	line = extract_line(stock, &count);
	trim_list(&stock);
	return (line);
}*/



