/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:02:29 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 09:55:18 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_cases(t_so_long *sl)
{
	if (sl->tab[sl->y_player][sl->x_player] == 'C')
		sl->collectible--;
	if (sl->tab[sl->y_player][sl->x_player] == 'M')
	{
		ft_printf("YOU LOSE");
		mlx_close_window(sl->mlx);
	}
	if (sl->tab[sl->y_player][sl->x_player] == 'E')
	{
		ft_printf("YOU WIN");
		mlx_close_window(sl->mlx);
	}
}

void	move_up(t_so_long *sl)
{
	if (sl->tab[sl->y_player - 1][sl->x_player] != '1')
	{
		if ((sl->tab[sl->y_player - 1][sl->x_player] == 'E')
			&& sl->collectible != 0)
			return ;
		else
		{
			print_char(sl);
			sl->tab[sl->y_player][sl->x_player] = '0';
			sl->texture = mlx_load_png("./images/black.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
			sl->y_player = sl->y_player - 1;
			exit_cases(sl);
			sl->tab[sl->y_player][sl->x_player] = 'P';
			sl->texture = mlx_load_png("./images/pacman_up.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
		}
	}
}

void	move_down(t_so_long *sl)
{
	if (sl->tab[sl->y_player + 1][sl->x_player] != '1')
	{
		if ((sl->tab[sl->y_player + 1][sl->x_player] == 'E')
			&& sl->collectible != 0)
			return ;
		else
		{
			print_char(sl);
			sl->tab[sl->y_player][sl->x_player] = '0';
			sl->texture = mlx_load_png("./images/black.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
			sl->y_player = sl->y_player + 1;
			exit_cases(sl);
			sl->tab[sl->y_player][sl->x_player] = 'P';
			sl->texture = mlx_load_png("./images/pacman_down.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
		}
	}
}

void	move_left(t_so_long *sl)
{
	if (sl->tab[sl->y_player][sl->x_player - 1] != '1')
	{
		if ((sl->tab[sl->y_player][sl->x_player - 1] == 'E')
			&& sl->collectible != 0)
			return ;
		else
		{
			print_char(sl);
			sl->tab[sl->y_player][sl->x_player] = '0';
			sl->texture = mlx_load_png("./images/black.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
			sl->x_player = sl->x_player - 1;
			exit_cases(sl);
			sl->tab[sl->y_player][sl->x_player] = 'P';
			sl->texture = mlx_load_png("./images/pacman_left.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
		}
	}
}

void	move_right(t_so_long *sl)
{
	if (sl->tab[sl->y_player][sl->x_player + 1] != '1')
	{
		if ((sl->tab[sl->y_player][sl->x_player + 1] == 'E')
			&& sl->collectible != 0)
			return ;
		else
		{
			print_char(sl);
			sl->tab[sl->y_player][sl->x_player] = '0';
			sl->texture = mlx_load_png("./images/black.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
			sl->x_player = sl->x_player + 1;
			exit_cases(sl);
			sl->tab[sl->y_player][sl->x_player] = 'P';
			sl->texture = mlx_load_png("./images/pacman_right.png");
			texture_to_image(sl, sl->y_player, sl->x_player);
		}
	}
}
