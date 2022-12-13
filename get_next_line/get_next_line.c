/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:47 by amouly            #+#    #+#             */
/*   Updated: 2022/12/13 16:56:48 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	fill_node(t_list **stock, int fd)
{
	t_list	*new;
	int		lu;

//	if (*stock == NULL)
//		return(0);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->str = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (new->str == NULL)
	{
		free(new);
		return (0);
	}
	lu = read(fd, new->str, BUFFER_SIZE);
	if (lu <= 0)
	{	
		free(new->str);
		free(new);
		return (0);
	}
	new->str[lu] = '\0';
	new->next = NULL;
	ft_lstadd_back(stock, new);
//	if (*stock == NULL)
//		return (0);
	return (1);
}

char	*extract_line(t_list *stock, int count)
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

void	trim_list(t_list **stock)
{
	t_list	*temp;
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
	static t_list	*stock = NULL;
	int				count;
	char			*line;

	line = NULL;
	count = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!(check_new_line(stock)))
	{
		if (clean_stock (&stock, fd, line))
			return (NULL);
		if (!(fill_node(&stock, fd)))
		{
			if (stock && stock->str)
				break ;
			return (NULL);
		}
	}
	count = count_char_line(stock);
	line = extract_line(stock, count);
	trim_list(&stock);
	return (line);
}
