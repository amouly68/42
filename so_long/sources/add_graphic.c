
#include "so_long.h"

mlx_image_t         *img_player;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
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
}

int     load_texture(mlx_t *mlx, t_so_long *sl)
{
    int i;
    int j;
    mlx_texture_t   *texture;
    mlx_image_t         *img;

    i = 0;
    texture = NULL;
    while(sl->tab[i])
    {
        
        j = 0;
        while(sl->tab[i][j])
        {
            if (sl->tab[i][j] == '1')
            {
                texture = mlx_load_png("./images/lava.png");
                texture->height = 64;
                texture->width = 64;
                img = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img, j * 64, i * 64);
            }
            else if (sl->tab[i][j] == '0')
            {
                texture = mlx_load_png("./images/black.png");
                texture->height = 64;
                texture->width = 64;
                img = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img, j * 64, i * 64);
            }
            else if (sl->tab[i][j] == 'P')
            {
                texture = mlx_load_png("./images/pacman_black.png");
                texture->height = 64;
                texture->width = 64;
                img_player = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img_player, j * 64, i * 64);
            }
            else if (sl->tab[i][j] == 'C')
            {
                texture = mlx_load_png("./images/cherry_black.png");
                texture->height = 64;
                texture->width = 64;
                img = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img, j * 64, i * 64);
            }
            else if (sl->tab[i][j] == 'E')
            {
                texture = mlx_load_png("./images/exit.png");
                texture->height = 64;
                texture->width = 64;
                img = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img, j * 64, i * 64);
            }
            j++;
        }
        i++;
    }
    return (1);
}



int add_graphic(t_so_long *sl)
{
    mlx_t   *mlx;

    
    mlx = mlx_init(sl->map_width * 64, sl->map_height * 64, "SO_LONG", true);
    if (!mlx)
		exit(EXIT_FAILURE);
    if (!(load_texture(mlx,sl)))
        return (0);
    mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
    
}