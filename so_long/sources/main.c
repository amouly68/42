
#include "so_long.h"

int main (int argc, char **argv)
{
    int fd;
    t_so_long   sl;
   
    
    if(!(check_error(argc, argv)))
        return (-1);
    init_sl(&sl);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Map n'existe pas\n");
        return (-1);
    }    
    if (!(parse_map(&sl, fd)))
        return (-1);
    if (!(add_graphic(&sl)))
        return (-1);
    //ft_printf("YO");
    free(sl.tab);
    sl.tab = NULL;
    free_list(&(sl.map));
    system ("leaks so_long");
    
}

/*#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 512
#define HEIGHT 512

mlx_image_t	        *g_img;
mlx_image_t         *img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int	main(void)
{
    mlx_t               *mlx;   
    mlx_texture_t       *texture_png = NULL; 
    char                *path = "./images/pacman_black.png";
    char                *path2 = "./images/black.png";
   // uint32_t    xy[2] = {0,0};
    //uint32_t    wh[2] = {64,64};


    mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
    g_img = mlx_new_image(mlx, 128, 128);
   
    texture_png = mlx_load_png(path2);
    img = mlx_texture_to_image(mlx, texture_png);
    mlx_image_to_window(mlx, img, 64, 0);
    texture_png = mlx_load_png(path);
    texture_png->height = 64;
    texture_png->width = 64;
	img = mlx_texture_to_image(mlx, texture_png);
    //memset(img->pixels, 255, img->width * img->height * sizeof(int));
	//memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
    //mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/