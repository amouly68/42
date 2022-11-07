/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:04:32 by amouly            #+#    #+#             */
/*   Updated: 2022/11/07 10:07:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == c)
			i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		if (str[i] == '\0' || str[i] == c)
			count++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	return (count);
}

int	long_mot(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] == '\0' || str[i] == c)
		return (count);
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab ;
	int		i;
	int		pos;
	int		j;
	int		a;

	i = -1;
	a = 0;
	pos = 0;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	while (++i < count_word(s, c))
	{
		while (long_mot(&s[pos], c) == 0)
			pos++;
		tab[i] = malloc (sizeof(char) * (long_mot(&s[pos], c) + 1));
		j = -1;
		while ((s[pos] != c) && s[pos] != '\0' )
		{	
			tab[i][++j] = s[pos];
			pos++;
		}
	tab[i][++j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
