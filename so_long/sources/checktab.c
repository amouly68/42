/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:43:57 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 10:07:31 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_addnode_c_back(t_point **list, t_point *new)
{
	t_point	*temp;

	if (list == NULL && new == NULL)
		return (0);
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
	return (1);
}

void	fill_list_collectible(t_so_long *sl, int i, int j)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return ;
	new->x_point = j;
	new->y_point = i;
	new->next = NULL;
	if (!(ft_addnode_c_back(&sl->collect_list, new)))
		return ;
}

void	find_coordonates(t_so_long *sl)
{
	int	i;
	int	j;

	i = 1;
	while (sl->tab[i])
	{
		j = 1;
		while (sl->tab[i][j])
		{
			if (sl->tab[i][j] == 'P')
			{
				sl->x_player = j;
				sl->y_player = i;
			}
			else if (sl->tab[i][j] == 'E')
			{
				sl->x_exit = j;
				sl->y_exit = i;
			}
			else if (sl->tab[i][j] == 'C')
				fill_list_collectible(sl, i, j);
			j++;
		}
		i++;
	}
}

int	error_wall(void)
{
	ft_printf("Error\nMap non entouree de murs\n");
	return (0);
}

int	check_tab(t_so_long *sl)
{
	int	i;

	i = 1;
	if (!(all_wall(sl->tab[0])))
		return (error_wall());
	if (!(all_wall(sl->tab[sl->map_height - 1])))
		return (error_wall());
	while (i < (sl->map_height - 1))
	{
		if (!(line_wall(sl->tab[i])))
			return (error_wall());
		i++;
	}
	find_coordonates(sl);
	if (!(flood_fill(sl)))
	{
		ft_printf("Error\nMap non jouable\n");
		return (0);
	}
	return (1);
}
