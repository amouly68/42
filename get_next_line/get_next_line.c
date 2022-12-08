/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/08 17:15:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	fill_node(s_list **stock, int fd)
{
	s_list	*new;
	int		lu;

	new = malloc(sizeof(s_list));
	if (new == NULL)
		return (0);
	new->str = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (new->str == NULL)
		return (0);
	lu = read(fd, new->str, BUFFER_SIZE);
	if (lu <= 0)
		return (0);
	new->str[lu] = '\0';
	new->next = NULL;
	ft_lstadd_back(stock, new);
	return (1);
}

char	*extract_line(s_list *stock, int count)
{
	int		i;
	int		b;
	char	*ret;

	b = 0;
	if (stock == NULL || count == 0)
		return (NULL);
	ret = malloc (sizeof(char) * (count + 1));
	if (ret == NULL)
		return (NULL);
	while (stock)
	{
		i = 0;
		while (stock->str[i] != '\0' && stock->str[i] != '\n')
			ret[b++] = stock->str[i++];
		if (stock->str[i] == '\n')
			ret[b++] = '\n';
		stock = stock->next;
	}
	ret[b] = '\0';
	if (b == 0)
		return (NULL);
	return (ret);
}

char	*trim_str(char *str)
{
	int		a;
	int		b;
	int		c;
	char	*temp;

	temp = str;
	a = 0;
	b = 0;
	while (str[a] != '\0')
		a++;
	while (str[b] != '\n')
		b++;
	b++;
	c = a - b;
	temp = malloc(sizeof(char) * (c + 1));
	if (temp == NULL)
		return (NULL);
	a = 0;
	while (a < c)
		temp[a++] = str[b++];
	temp[a] = '\0';
	return (temp);
}

void	trim_list(s_list **stock)
{
	s_list	*temp;
	char	*str_tmp;

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
	{
		str_tmp = trim_str((*stock)->str);
		free((*stock)->str);
		((*stock)->str) = str_tmp;
	}
}

char	*get_next_line(int fd)
{
	static s_list	*stock = NULL;
	int				count;
	char			*line;

	line = NULL;
	count = 0;
	if (fd <= 0 || BUFFER_SIZE < 1 || read(fd, line, 0) == -1)
		return (NULL);
	while (!(check_new_line(stock)))
	{
		if (!(fill_node(&stock, fd)))
		{
			trim_list(&stock);
			if (stock)
			{
				if (stock->str)
					free(stock->str);
				free(stock);
				stock = NULL;
			}
			return (NULL);
		}
	}
	count = count_char_line(stock);
	line = extract_line(stock, count);
	trim_list(&stock);
	return (line);
}
