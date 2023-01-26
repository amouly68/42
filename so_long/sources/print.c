/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:39:24 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 10:15:56 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_list(t_map *list)
{
	int	i;

	i = 0;
	while (list)
	{
		ft_printf("noeud %d : %s\n", i, list->line);
		i++;
		list = list->next;
	}
}

void	print_l(t_point *list)
{
	int	i;

	i = 0;
	while (list)
	{
		ft_printf("Collectible num %d -- x : %d  | y : %d \n", i, list->x_point,
			list->y_point);
		i++;
		list = list->next;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	ft_printf("%s", tab[i]);
}
