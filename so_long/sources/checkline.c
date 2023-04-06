/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:01:27 by amouly            #+#    #+#             */
/*   Updated: 2023/01/31 09:45:44 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

int	all_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	line_wall(char *line)
{
	int	end;

	end = ft_strlen(line) - 1;
	if (line[0] != '1')
		return (0);
	if (line[end] != '1')
		return (0);
	return (1);
}

int	char_line_ok(char *line, t_so_long *sl)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C' || line[i] == 'E'
			|| line[i] == 'P')
		{
			if (line[i] == 'C')
				sl->collectible++;
			if (line[i] == 'E')
				sl->exit++;
			if (line[i] == 'P')
				sl->position++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	all_one(char *line)
{
	int	i;

	i = 0;
	while (i < len_line(line))
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
