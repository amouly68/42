
#include "so_long.h"

mlx_image_t         *img_player;

/*void	hook(void *param)
{
	t_so_long                   *sl;
    mlx_t		                *mlx;
    mlx_image_t         *img_player;

	sl = param;
    mlx = sl->mlx;
    img_player = sl->img_player;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img_player->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img_player->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img_player->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img_player->instances[0].x += 5;
}*/

void texture_to_image(t_so_long *sl, int i, int j)
{
    sl->texture->height = 64;
    sl->texture->width = 64;
    sl->img = mlx_texture_to_image(sl->mlx, sl->texture);
    mlx_image_to_window(sl->mlx, sl->img, j * 64, i * 64);

}

int     load_texture(t_so_long *sl)
{
    int i;
    int j;

    i = 0;
    while(sl->tab[i])
    { 
        j = 0;
        while(sl->tab[i][j])
        {
            if (sl->tab[i][j] == '1' )
                sl->texture = mlx_load_png("./images/lava.png");
            else if (sl->tab[i][j] == '0')
                sl->texture = mlx_load_png("./images/black.png");
            else if (sl->tab[i][j] == 'P')
            {
                sl->texture = mlx_load_png("./images/pacman_black.png");
                sl->img_player = mlx_texture_to_image(sl->mlx, sl->texture);
                mlx_image_to_window(sl->mlx, sl->img_player, j * 64, i * 64);
            }
            else if (sl->tab[i][j] == 'C')
                sl->texture = mlx_load_png("./images/cherry_black.png");
            else if (sl->tab[i][j] == 'E')
                sl->texture = mlx_load_png("./images/exit.png");
            texture_to_image(sl, i, j);
            j++;
        }
        i++;
    }
    return (1);
}

void	hook_key(mlx_key_data_t  keydata, void *param)
{
	t_so_long                   *sl;
    mlx_t		                *mlx;
    mlx_image_t         *img_player;

	sl = param;
    mlx = sl->mlx;
    img_player = sl->img_player;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == 1)
		mlx_close_window(mlx);
	else if ((keydata.key == MLX_KEY_UP) && keydata.action == 1)
		{
            if (sl->tab[sl->y_player - 1][sl->x_player] != '1')
            {
                sl->tab[sl->y_player][sl->x_player] = '0';
                sl->texture = mlx_load_png("./images/black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
                sl->y_player = sl->y_player - 1;
                sl->tab[sl->y_player][sl->x_player] = 'P';
                sl->texture = mlx_load_png("./images/pacman_black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
            }
        }
	else if ((keydata.key ==  MLX_KEY_DOWN) && keydata.action == 1)
		{
            if (sl->tab[sl->y_player + 1][sl->x_player] != '1')
            {
                sl->tab[sl->y_player][sl->x_player] = '0';
                sl->texture = mlx_load_png("./images/black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
                sl->y_player = sl->y_player + 1;
                sl->tab[sl->y_player][sl->x_player] = 'P';
                sl->texture = mlx_load_png("./images/pacman_black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
            }
        }
	else if ((keydata.key == MLX_KEY_LEFT) && keydata.action == 1)
		{
            if (sl->tab[sl->y_player][sl->x_player - 1] != '1')
            {
                sl->tab[sl->y_player][sl->x_player] = '0';
                sl->texture = mlx_load_png("./images/black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
                sl->x_player = sl->x_player - 1;
                sl->tab[sl->y_player][sl->x_player] = 'P';
                sl->texture = mlx_load_png("./images/pacman_black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
            }
        }
	else if ((keydata.key == MLX_KEY_RIGHT) && keydata.action == 1)
		{
            if (sl->tab[sl->y_player][sl->x_player + 1] != '1')
            {
                sl->tab[sl->y_player][sl->x_player] = '0';
                sl->texture = mlx_load_png("./images/black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
                sl->x_player = sl->x_player + 1;
                sl->tab[sl->y_player][sl->x_player] = 'P';
                sl->texture = mlx_load_png("./images/pacman_black.png");
                texture_to_image(sl, sl->y_player, sl->x_player);
            }
        }
      //if (!(load_texture(sl)))
       //return ;    
}



int add_graphic(t_so_long *sl)
{
     
    sl->mlx = mlx_init(sl->map_width * 64, sl->map_height * 64, "SO_LONG", true);
    if (!(sl->mlx))
		exit(EXIT_FAILURE);
    if (!(load_texture(sl)))
        return (0);
    mlx_key_hook(sl->mlx, &hook_key, sl);
	mlx_loop(sl->mlx);
	mlx_terminate(sl->mlx);
	return (1);
    
}