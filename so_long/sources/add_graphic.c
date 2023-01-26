/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:56:50 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 11:59:46 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(t_so_long *sl, int i, int j)
{
	sl->texture->height = 64;
	sl->texture->width = 64;
	sl->img = mlx_texture_to_image(sl->mlx, sl->texture);
	mlx_image_to_window(sl->mlx, sl->img, j * 64, i * 64);
	mlx_delete_texture(sl->texture);
}

int	load_texture(t_so_long *sl)
{
	int	i;
	int	j;

	i = -1;
	while (sl->tab[++i])
	{
		j = -1;
		while (sl->tab[i][++j])
		{
			if (sl->tab[i][j] == '1')
				sl->texture = mlx_load_png("./images/lava.png");
			else if (sl->tab[i][j] == '0')
				sl->texture = mlx_load_png("./images/black.png");
			else if (sl->tab[i][j] == 'M')
				sl->texture = mlx_load_png("./images/phantom_64.png");
			else if (sl->tab[i][j] == 'P')
				sl->texture = mlx_load_png("./images/pacman_black.png");
			else if (sl->tab[i][j] == 'C')
				sl->texture = mlx_load_png("./images/cherry_black.png");
			else if (sl->tab[i][j] == 'E')
				sl->texture = mlx_load_png("./images/exit.png");
			texture_to_image(sl, i, j);
		}
	}
	return (1);
}

void	print_char(t_so_long *sl)
{
	char	*ret;
	char	*itoa;

	sl->steps++;
	itoa = ft_itoa(sl->steps);
	ret = ft_strjoin("Nombre de move : ", itoa);
	ft_printf("nombre de move : %d\n", sl->steps);
	mlx_delete_image(sl->mlx, sl->text);
	sl->text = mlx_put_string(sl->mlx, ret, 0, 0);
	free(ret);
	free(itoa);
}

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_so_long	*sl;
	mlx_t		*mlx;

	sl = param;
	mlx = sl->mlx;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == 1)
		mlx_close_window(mlx);
	if ((keydata.key == MLX_KEY_W) && keydata.action == 1)
		move_up(sl);
	if ((keydata.key == MLX_KEY_S) && keydata.action == 1)
		move_down(sl);
	if ((keydata.key == MLX_KEY_A) && keydata.action == 1)
		move_left(sl);
	if ((keydata.key == MLX_KEY_D) && keydata.action == 1)
		move_right(sl);
}

int	add_graphic(t_so_long *sl)
{
	sl->mlx = mlx_init(sl->map_width * 64, sl->map_height * 64, "SO_LONG",
			true);
	if (!(sl->mlx))
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (!(load_texture(sl)))
		return (0);
	sl->text = mlx_put_string(sl->mlx, "nombre de move : 0", 0, 0);
	mlx_key_hook(sl->mlx, &hook_key, sl);
	mlx_loop(sl->mlx);
	mlx_terminate(sl->mlx);
	return (1);
}
