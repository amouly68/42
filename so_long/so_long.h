/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:34:04 by amouly            #+#    #+#             */
/*   Updated: 2023/01/18 18:05:30 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct l_list
{
	char			*line;
	struct l_list	*next;
}					t_map;


typedef struct s_so_long
{
	t_map				**map;
	int					map_height;
	int					map_width;
	char				**tab;
		
}					t_so_long;


// print
void print_list(t_map *list);
void print_tab(char **tab) ;

// free 
void free_list(t_map **list);
void free_tab(char **tab);

// parse map.c





#endif
