/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2023/01/25 16:04:52 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <memory.h>


typedef struct l_list
{
	char			*line;
	struct l_list	*next;
}					t_map;

typedef struct l_list_coll
{
	int 				x_point;
	int					y_point;
	struct l_list_coll	*next;
}					t_point;


typedef struct s_so_long
{
	t_map				*map;
	t_point				*collect_list;
	char				**tab;
	int					map_height;
	int					map_width;
	int					collectible;
	int					exit;
	int					position;
	
	int					x_player;
	int					y_player;
	int					x_exit;
	int					y_exit;

	mlx_t				*mlx;
	mlx_texture_t		*texture;
	mlx_image_t			*img;
	mlx_image_t			*img_player;
	
	
		
}					t_so_long;


// print
void print_list(t_map *list);
void print_tab(char **tab) ;
void print_l(t_point *list);

// free 
void free_list(t_map **list);
void free_tab(char **tab);

// parse map.c
int	parse_map(t_so_long *sl, int fd);
void    init_sl(t_so_long *sl);
int	ft_addnode_back(t_map **list, t_map *new);

//checkline
int len_line(char *line);
int all_one(char *line);
int char_line_ok(char *line, t_so_long *sl);

// checklist
int map_rectangle(t_so_long *sl);
int char_ok(t_so_long *sl);
int	check_list(t_so_long *sl);

// argerror
int check_error(int argc, char **argv);

// checktab
int check_tab(t_so_long *sl);
void find_E_P(t_so_long *sl);

//add_graphic
int add_graphic(t_so_long *sl);

//flod_fill
int flood_fill(t_so_long *sl);




#endif
